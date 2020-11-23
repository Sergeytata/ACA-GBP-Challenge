#pragma once
#include <vector>
#include <memory>
#include <factor.h>
#include <variable.h>
#include <utility>
#include <map>
// #include <future>
#include <vector>
// #include <iostream>
#include <omp.h>
#define THREAD_NUM 4


// #include <execution>
// #include <thread>
class FactorGraph {
private:
    std::vector<std::shared_ptr<Factor>> factors_;
    std::vector<std::unique_ptr<Variable>> variables_;
    int variables_size = variables_.size();
    int factors_size = factors_.size();
    // std::future<void> variable_futures_ [5000];
    // std::future<void> factors_futures_ [10000];
    // std::vector<std::future<void>> variable_futures_;
public:
    std::map<Factor*, std::pair<int,int>> factors_table;
    // typedef std::map<std::shared_ptr<Factor>, std::pair<int,int>>* table_ptr;
    std::vector<std::shared_ptr<Factor>> get_factors(){return this->factors_;};

    FactorGraph() {}
    Variable *add_variable(const std::string &variable_id) {
        variables_.emplace_back(std::unique_ptr<Variable>(new Variable(variable_id)));
        return variables_.back().get();
    }
    Factor *add_factor(const std::string &factor_id) {
        factors_.emplace_back(std::unique_ptr<Factor>(new Factor(factor_id)));
        return factors_.back().get();
    }
    void connect(Factor *factor, std::initializer_list<size_t> variables) {
        for (size_t v : variables) {
            factor->add_neighbor(variables_[v].get());
        }
    }
    void iteration() {
        // int variables_size = variables_.size();
        int factors_size = factors_.size();

    
        
        // omp_set_dynamic(0);
        // omp_set_num_threads(THREAD_NUM);
        // #pragma omp parallel for
            for (size_t i = 0; i < variables_.size() ; i++) {
                auto &variable = variables_[i];
                variable->update_belief(&factors_table);
            }

        // std::cout << "The first loop is passed\n";
        // for (auto &variable : variables_) {
        //     variable->update_belief();
        // }
        // #pragma omp parallel for
        // for (auto &factor: factors_) {
            // for (size_t i = 0; i < factors_size ; i++) {
            //     auto &factor = factors_[i];
            //     factor->update_factor();
            // }

        // #pragma omp parallel for
        for (auto &variable : variables_) {
        // for (size_t i = 0; i < variables_.size() ; i++) {
            // auto &variable = variables_[i];
            variable->send_messages();
        }
        // #pragma omp parallel for
        // for (auto &factor: factors_) {
        for (size_t i = 0; i < factors_.size() ; i++) {
            auto &factor = factors_[i];
            factor->send_messages();
        }
    }
    double ARE() const {
        double residual_error = 0.f;
        for (auto &factor: factors_) {
            residual_error += factor->residual();
        }
        return residual_error;

    }

    const Variable *v(size_t i) const { return variables_[i].get(); }
    const Factor *f(size_t i) const { return factors_[i].get(); }
};
