
undefined4 * __thiscall
FUN_00401e31(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_LAB_00666514;
  param_1[4] = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  uVar1 = (**(code **)(*param_2 + 0x1c))();
  param_1[5] = uVar1;
  if ((DAT_006de70c - DAT_006de708) / 0x54 != 0) {
    FUN_00401e97(param_1,param_3);
    FUN_00401e97(param_1,param_4);
    FUN_00401e97(param_1,param_5);
  }
  return param_1;
}

