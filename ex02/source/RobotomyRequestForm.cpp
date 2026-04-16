#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <unistd.h>

#include "miniaudio.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(
    name, 72, 45) {
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!getSigned())
        throw FormNeedSign();
    if (executor.getGrade() > getReqExec())
        throw GradeTooLowException();
    srand(time(0));
    ma_engine engine;
    ma_result result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS)
        throw AudioEngineError();

    if(ma_engine_play_sound(&engine, "dril.mp3", NULL) !=  MA_SUCCESS)
        throw AudioEngineError();
    std::cout << "*drill noise*" << std::endl;
    sleep(5);
    if (rand() % 2) {
        std::cout << executor << " has been robotomized" << std::endl;
    } else {
        std::cout << "Failed robotomy on " << executor << std::endl;
    }
    ma_engine_uninit(&engine);
}


std::runtime_error RobotomyRequestForm::AudioEngineError() {
    return std::runtime_error("failed to initialize miniaudio");
}
std::invalid_argument RobotomyRequestForm::WrongAudioFile() {
    return std::invalid_argument("invalid audio file");
}

