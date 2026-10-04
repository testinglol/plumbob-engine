
undefined4 __thiscall FUN_005fbcb1(int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_retaddr;
  
  pvVar1 = operator_new(param_1[7]);
  *param_2 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar3 = (**(code **)(*param_1 + 0x10))(pvVar1,param_1[7]);
    if (unaff_retaddr != (int *)0x0) {
      *unaff_retaddr = iVar3;
    }
    if (iVar3 != param_1[7]) {
      FUN_006321f0(*param_2);
      *param_2 = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

