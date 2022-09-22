#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  //Iterate on total number of batteries
  for(int i=0;i<nBatteries;i++)
  {
      //This condition checks if the charge cycle for a battery is less than 410
      if(cycles[i]<410)
        counts.lowCount=counts.lowCount+1; //Increment the count of the low charge batteries by 1
     //This condition checks if the charge cycle for a battery is between  410 and 909
      else if(cycles[i]>=410 && cycles[i]<=909)
        counts.mediumCount=counts.mediumCount+1; //Increment the count of the medium charge batteries by 1
    //This condition checks if the charge cycle for a battery is greater than or equal to 910
      else
        counts.highCount=counts.highCount+1; //Increment the count of the high charge batteries by 1
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300,409, 410, 600, 909,910, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 3);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 2);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
