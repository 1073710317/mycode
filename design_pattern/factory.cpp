/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file factory.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/08/18 11:42:59
 * @version $Revision$ 
 * @brief 工厂模式
 *  
 **/

#include <iostream>

class IHuman {
public:
    virtual void laugh() = 0;

    virtual void cry() = 0;

    virtual void talk() = 0;
};

class CYellowHuman : public IHuman {
public:
    void laugh() {
        std::cout << "CYellowHuman laugh" << std::endl;
    }

    void cry() {
        std::cout << "CYellowHuman cry" << std::endl;
    }

    void talk() {
        std::cout << "CYellowHuman talk" << std::endl;
    }
};

class CWhiteHuman : public IHuman {
public:
    void laugh() {
        std::cout << "CWhiteHuman laugh" << std::endl;
    }

    void cry() {
        std::cout << "CWhiteHuman cry" << std::endl;
    }

    void talk() {
        std::cout << "CWhiteHuman talk" << std::endl;
    }
};

class CBlackHuman : public IHuman {
public:
    void laugh() {
        std::cout << "CBlackHuman laugh" << std::endl;
    }

    void cry() {
        std::cout << "CBlackHuman cry" << std::endl;
    }

    void talk() {
        std::cout << "CBlackHuman talk" << std::endl;
    }
};

class IHumanFactory {
public:
    virtual IHuman* create_human() = 0;
};

class CYellowHumanFactory : public IHumanFactory {
public:
    IHuman* create_human() {
        return new CYellowHuman();
    }
};

class CWhiteHumanFactory : public IHumanFactory {
public:
    IHuman* create_human() {
        return new CWhiteHuman();
    }
};

class CBlackHumanFactory : public IHumanFactory {
public:
    IHuman* create_human() {
        return new CBlackHuman();
    }
};


int main() {
    IHumanFactory* yellow_human_factory = new CYellowHumanFactory();
    IHuman* yellow_human = yellow_human_factory->create_human();
    yellow_human->laugh();
    yellow_human->cry();
    yellow_human->talk();


    IHumanFactory* white_human_factory = new CWhiteHumanFactory();
    IHuman* white_human = white_human_factory->create_human();
    white_human->laugh();
    white_human->cry();
    white_human->talk();


    IHumanFactory* black_human_factory = new CBlackHumanFactory();
    IHuman* black_human = black_human_factory->create_human();
    black_human->laugh();
    black_human->cry();
    black_human->talk();

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
