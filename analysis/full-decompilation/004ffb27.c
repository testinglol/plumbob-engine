
void FUN_004ffb27(int *param_1,int *param_2)

{
  DWORD DVar1;
  
  DVar1 = timeGetTime();
  FUN_004734bd((float)*param_1,(float)*param_2,500,DVar1);
  FUN_004734bd((float)param_1[1],(float)param_2[1],500,DVar1);
  FUN_004734bd((float)param_1[2],(float)param_2[2],500,DVar1);
  FUN_004734bd((float)param_1[3],(float)param_2[3],500,DVar1);
  return;
}

