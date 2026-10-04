
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00585de3(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  
  *(char *)((int)param_1 + 0x109) = *(char *)((int)param_1 + 0xd9);
  if (*(char *)((int)param_1 + 0xd9) == '\0') {
    if (_DAT_0066657c <= (float)param_1[0x23] + (float)param_1[0x20]) {
      if ((_DAT_0066657c <= (float)param_1[0x24] + (float)param_1[0x21]) && (DAT_006d0430 != '\0'))
      {
        iVar2 = (**(code **)(*param_1 + 0xac))();
        if (iVar2 != 0) {
          param_1[0x1e] = 0;
          piVar3 = param_1 + 0xe;
          iVar2 = FUN_00415707(param_2);
          iVar2 = iVar2 + 0xec;
          (**(code **)(*param_1 + 0xac))(piVar3,iVar2);
          uVar1 = FUN_005a0912(piVar3,iVar2,param_2);
          *(undefined1 *)((int)param_1 + 0x109) = uVar1;
        }
      }
    }
  }
  return *(undefined1 *)((int)param_1 + 0x109);
}

