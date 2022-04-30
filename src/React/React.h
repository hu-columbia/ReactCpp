//
// Created by Hu Zheng on 2022/4/28.
//

#ifndef REACTCPP_REACT_H
#define REACTCPP_REACT_H

struct Nothing {};

class ReactNode {

};

template<class Props, class States>
class Component {
 private:
  Props props;
  States states;
 public:
  Component() {

  }
  Component(Props &props) {

  }

  Component(Props &&props) {

  }
 public:
  virtual ReactNode render() = 0;

  virtual void setState(States &state) {
    if (this->states != state) {
      this->states = state;
      render();
    }
  }
};

// The hyperscript function, used
ReactNode h() {

}

#endif //REACTCPP_REACT_H
