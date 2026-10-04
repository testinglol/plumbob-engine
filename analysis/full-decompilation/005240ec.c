
undefined4 __fastcall FUN_005240ec(int *param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = (param_2[3] - param_1[1]) - 1U | (param_1[3] - param_2[1]) - 1U |
          (param_2[2] - *param_1) - 1U | (param_1[2] - *param_2) - 1U;
  return CONCAT31((int3)(uVar1 >> 8),-1 < (int)uVar1);
}

