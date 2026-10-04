
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_004a39a0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,char param_6)

{
  double dVar1;
  float10 fVar2;
  double dVar3;
  
  dVar3 = (double)param_2 - (double)param_4 * _DAT_00667270;
  dVar1 = (double)param_5 - ((double)param_3 + (double)param_3);
  fVar2 = (float10)FUN_00636264(dVar3 * dVar3 + dVar1 * dVar1,param_1,param_1);
  dVar3 = (double)(fVar2 * (float10)_DAT_006682f8);
  fVar2 = (float10)FUN_00636264();
  return (float10)dVar3 / ((float10)(0x40 >> (3U - param_6 & 0x1f)) * fVar2);
}

