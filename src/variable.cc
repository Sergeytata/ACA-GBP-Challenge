#include <variable.h>
#include <factor.h>

Variable::Variable(const std::string &id) : id_(id) {}

const std::string Variable::id() const { return id_; }

void Variable::add_neighbor(Factor *f) { neighbors_.push_back(f); }
void Variable::set_prior(const Gaussian &prior) { prior_ = prior; }
void Variable::add_message(const std::string &from, const Gaussian &message) { inbox_[from] = message; }
const Gaussian &Variable::belief() const { return belief_; }

void Variable::update_belief() {
    Eigen::VectorXd eta = prior_.eta();
    Eigen::MatrixXd lam = prior_.lam();
    // #pragma omp parallel for
    // size_t i = 0;
    // Factor *f = neighbors_[0];
    // if (inbox_.count(f->id())) {
    //     eta += inbox_[f->id()].eta();
    //     lam += inbox_[f->id()].lam();
    // }
    // ++i;
    
    // #pragma omp parallel for
    // for (Factor *f : neighbors_) {
    for (size_t i = 0; i < neighbors_.size(); i++){
        Factor *f = neighbors_[i];
        if (inbox_.count(f->id())) {
            eta += inbox_[f->id()].eta();
            lam += inbox_[f->id()].lam();
        }
    }
    belief_ = Gaussian(eta, lam);
}

void Variable::send_messages() {
    // #pragma omp parallel for
    for (Factor *f : neighbors_) {
    // for (size_t i = 0; i < neighbors_.size(); i++){
        // Factor *f = neighbors_[i];
        Gaussian msg = belief_;
        if (inbox_.count(f->id())) {
            msg.eta() -= inbox_[f->id()].eta();
            msg.lam() -= inbox_[f->id()].lam();
        }
        f->add_message(id_, msg);
    }
}
