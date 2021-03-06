#ifndef __SEQMAN_TEST_HPP__
#define __SEQMAN_TEST_HPP__

#include "../sequenceManager/seqMan.hpp"

TEST(SequenceManager, ReadOUT_SEQ_ONE_I){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_ONE]");
    
    str << dia.strOUT();
    EXPECT_EQ(str.str(), "Fire is the rapid oxidation of a\n");

    str.str(std::string()); str << dia.strOUT();
    EXPECT_EQ(str.str(), "material in the exothermic\n");

    str.str(std::string()); str << dia.strOUT();
    EXPECT_EQ(str.str(), "chemical process of combustion,\n");

    str.str(std::string()); str << dia.strOUT();
    EXPECT_EQ(str.str(), "releasing heat, light, and various reaction products.\n");
}

TEST(SequenceManager, ReadOUT_SEQ_ONE_II){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_ONE]");
    
    for(int i = 0; i < 3; ++i) {
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Fire is the rapid oxidation of a\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "material in the exothermic\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "chemical process of combustion,\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "releasing heat, light, and various reaction products.\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_ONE_III){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_ONE]");
    
    for(int i = 0; i < 3; ++i) {    
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Fire is the rapid oxidation of a\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "material in the exothermic\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "chemical process of combustion,\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "releasing heat, light, and various reaction products.\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_ONE_IV){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_ONE]");

    dia.OUT(2, str);
    EXPECT_EQ(str.str(), "chemical process of combustion,\n");

    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "releasing heat, light, and various reaction products.\n");

    str.str(std::string()); dia.OUT(3, str);
    EXPECT_EQ(str.str(), "releasing heat, light, and various reaction products.\n");

    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "Fire is the rapid oxidation of a\n");

    str.str(std::string()); dia.OUT(2, str);
    EXPECT_EQ(str.str(), "chemical process of combustion,\n");

    str.str(std::string()); dia.OUT(1, str);
    EXPECT_EQ(str.str(), "material in the exothermic\n");

    str.str(std::string()); dia.OUT(0, str);
    EXPECT_EQ(str.str(), "Fire is the rapid oxidation of a\n");
}

TEST(SequenceManager, ReadOUT_SEQ_TWO_I){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_TWO]");

    str << dia.strOUT();
    EXPECT_EQ(str.str(), "Fire is hot because\nthe conversion of\n");

    str.str(std::string()); str << dia.strOUT();
    EXPECT_EQ(str.str(), "the weak double bond in molecular oxygen,\nO2, to the stronger bonds in\n");

    str.str(std::string()); str << dia.strOUT();
    EXPECT_EQ(str.str(), "the combustion products carbon\ndioxide and water releases energy (418 kJ per 32 g of O2);\n");
}

TEST(SequenceManager, ReadOUT_SEQ_TWO_II){
        seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_TWO]");
    
    for(int i = 0; i < 3; ++i) {
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Fire is hot because\nthe conversion of\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "the weak double bond in molecular oxygen,\nO2, to the stronger bonds in\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "the combustion products carbon\ndioxide and water releases energy (418 kJ per 32 g of O2);\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_TWO_III){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_TWO]");
    
    for(int i = 0; i < 3; ++i) {
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Fire is hot because\nthe conversion of\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "the weak double bond in molecular oxygen,\nO2, to the stronger bonds in\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "the combustion products carbon\ndioxide and water releases energy (418 kJ per 32 g of O2);\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_TWO_IV){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_TWO]");

    dia.OUT(1, str);
    EXPECT_EQ(str.str(), "the weak double bond in molecular oxygen,\nO2, to the stronger bonds in\n");

    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "the combustion products carbon\ndioxide and water releases energy (418 kJ per 32 g of O2);\n");

    str.str(std::string()); dia.OUT(2, str);
    EXPECT_EQ(str.str(), "the combustion products carbon\ndioxide and water releases energy (418 kJ per 32 g of O2);\n");

    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "Fire is hot because\nthe conversion of\n");

    str.str(std::string()); dia.OUT(2, str);
    EXPECT_EQ(str.str(), "the combustion products carbon\ndioxide and water releases energy (418 kJ per 32 g of O2);\n");

    str.str(std::string()); dia.OUT(1, str);
    EXPECT_EQ(str.str(), "the weak double bond in molecular oxygen,\nO2, to the stronger bonds in\n");

    str.str(std::string()); dia.OUT(0, str);
    EXPECT_EQ(str.str(), "Fire is hot because\nthe conversion of\n");
}

TEST(SequenceManager, ReadOUT_SEQ_THREE){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_THREE]");

    for(int i = 0; i < 3; ++i){
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "the bond energies of the\nfuel play only a minor role here.\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "At a certain point in the combustion\nreaction, called the ignition point, flames are produced.\nThe flame is the visible portion of the fire. Flames consist\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "primarily of carbon dioxide, water vapor, oxygen and nitrogen.\nIf hot enough, the gases may become ionized to produce plasma.\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Depending on the substances alight, and any impurities outside,\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "the color of the flame and the fire's intensity will be different.\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_FOUR){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_FOUR]");

    for(int i = 0; i < 3; ++i){
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Fire in its most common form can result in conflagration,\n\nwhich has the potential to cause physical damage\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "\nthrough burning.\n\n");
    
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Fire is an important process\n\nthat affects ecological systems around the globe.\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "The positive effects of fire include stimulating growth and maintaining\n\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "various ecological systems. Its negative effects\n\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "include hazard to life and property,\natmospheric pollution, and water contamination.\nIf fire removes protective vegetation,\n\nheavy rainfall may lead to an increase in soil erosion by water.\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_FIVE){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_FIVE]");

    for(int i = 0; i < 3; ++i){
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "Also, when vegetation is burned,\nthe nitrogen it contains is released into the atmosphere,\nunlike elements such as potassium\nand phosphorus which remain in the ash and are quickly recycled into the soil.\n\nThis loss of nitrogen caused by a fire produces\na long-term reduction in the fertility of the soil,\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_SIX){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_SIX]");

    for(int i = 0; i < 3; ++i){
        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "but this fecundity can potentially be recovered as\n\nmolecular nitrogen in the atmosphere is \"fixed\" and\n\nconverted to ammonia by natural phenomena such as lightning\n\nand by leguminous plants that are \"nitrogen-fixing\"\n\n\nsuch as clover, peas, and green beans.\n");
    }
}

TEST(SequenceManager, ReadOUT_SEQ_SEVEN){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_SEVEN]");

    for(int i = 0; i < 3; ++i){
        str.str(std::string()); dia.OUT(3, str);
        EXPECT_EQ(str.str(), "smelting, forging, incineration of waste, cremation,\nand as a weapon or mode of destruction.\n");

        str.str(std::string()); dia.OUT(2, str);
        EXPECT_EQ(str.str(), "for signaling, propulsion purposes,\n");

        str.str(std::string()); dia.OUT(1, str);
        EXPECT_EQ(str.str(), "in agriculture for clearing land, for cooking, generating heat and light,\n");

        str.str(std::string()); dia.OUT(0, str);
        EXPECT_EQ(str.str(), "Fire has been used by humans in rituals,\n");

        str.str(std::string()); dia.OUT(-1, str);
        EXPECT_EQ(str.str(), "in agriculture for clearing land, for cooking, generating heat and light,\n");
    }
}

TEST(SequenceManager, ChangeTxt){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_SEVEN]");

    dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "Fire has been used by humans in rituals,\n");

    dia.file("unit_test/testDialogue/sampleTextTEST_TWO.txt");
    dia.sequence("[PART_ONE]");
    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "Apple\nBean\nClover\n");

    dia.file("unit_test/testDialogue/sampleTextTEST_ONE.txt");
    dia.sequence("[SEQ_TWO]");
    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "Fire is hot because\nthe conversion of\n");
}

TEST(SequenceManager, HotSwapSequence){
    seqMan dia;
    std::stringstream str;
    dia.file("unit_test/testDialogue/sampleTextTEST_TWO.txt");

    dia.sequence("[PART_FIVE]");
    dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "AAA\n\n\nBBB\n\n\nCCC\n\n\nDDD\n");

    dia.sequence("[PART_FOUR]");
    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "one\ntwo\nthree \nfour \nfive \nsix\nseven\n");

    dia.sequence("[PART_THREE]");
    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "If there was a dog\n\nwaiting at home,\n\nand it waited all day,\n\ndoes it write novels\n\nabout it?\n\n");

    dia.sequence("[PART_TWO]");
    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "Radiation\nMutiny\nRadio\nGinger\nBrussel\n");

    dia.sequence("[PART_ONE]");
    str.str(std::string()); dia.OUT(-1, str);
    EXPECT_EQ(str.str(), "Apple\nBean\nClover\n");
}


//--

#endif
