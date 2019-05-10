#pragma once
#ifndef w
#define w
class Weight
{

    public:
        Weight();
        void SetWeightPounds(double weightPounds);
        void SetWeightKilograms(double weightKilograms);
        void SetWeightOunces(double weightOunces);
        void ConvertPounds();
        void ConvertKilograms();
        void ConvertOunces();

    private:
        double _weightPounds;
        double _weightKilograms;
        double _weightOunces;

};




#endif