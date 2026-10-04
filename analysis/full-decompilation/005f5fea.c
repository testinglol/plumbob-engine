
undefined4 __thiscall FUN_005f5fea(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if ((char)param_1[0x47] == '\0') {
LAB_005f602e:
    uVar2 = 1;
  }
  else {
    cVar1 = FUN_005d98fc(param_1);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*param_1 + 0x1c0))(&param_3,param_2,param_3);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x1a8))(param_3);
        goto LAB_005f602e;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

