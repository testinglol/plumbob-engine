
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00593c86(float *param_1,float *param_2)

{
  undefined4 uVar1;
  
  if ((((_DAT_0067343c < ABS(*param_1 - *param_2)) || (_DAT_0067343c < ABS(param_1[1] - param_2[1]))
       ) || (_DAT_0067343c < ABS(param_1[2] - param_2[2]))) ||
     (_DAT_0067343c < ABS(param_1[3] - param_2[3]))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

