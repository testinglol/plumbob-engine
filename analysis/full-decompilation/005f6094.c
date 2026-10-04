
undefined4 __thiscall FUN_005f6094(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if ((char)param_1[0x47] == '\0') {
LAB_005f60d7:
    uVar3 = 1;
  }
  else {
    piVar2 = (int *)FUN_00492d2c();
    if (piVar2 == param_1) {
      cVar1 = (**(code **)(*param_1 + 0x1c0))(&param_3,param_2,param_3);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x1a8))(param_3);
        goto LAB_005f60d7;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

