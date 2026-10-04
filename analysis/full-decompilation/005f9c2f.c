
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005f9c2f(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int *local_8;
  
  cVar1 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar1 == '\0') {
LAB_005f9cf3:
    uVar3 = 1;
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x24))();
    if (cVar1 == '\0') {
LAB_005f9c67:
      cVar1 = FUN_005f98f3();
      if (cVar1 != '\0') {
        if (param_1[0x20] != 0) {
          (**(code **)(*param_1 + 0xf0))();
        }
        _memset(&local_18,0,0x14);
        local_18 = 0x14;
        local_10 = *(undefined4 *)(param_1[0x2f] + 4);
        local_8 = param_1 + 0x2a;
        local_14 = ((9 < param_1[0xe]) - 1 & 8) + 0x100e0;
        iVar2 = (**(code **)(*DAT_006fed6c + 0xc))(DAT_006fed6c,&local_18,param_1 + 0x20,0);
        if (iVar2 == 0) {
          _DAT_006fed50 = _DAT_006fed50 + 1;
          goto LAB_005f9cf3;
        }
      }
    }
    else if (param_2 != '\0') {
      (**(code **)(*param_1 + 0x28))();
      goto LAB_005f9c67;
    }
    uVar3 = 0;
  }
  return uVar3;
}

