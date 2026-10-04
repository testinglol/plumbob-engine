
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005f92a4(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  cVar2 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar2 != '\0') {
    if (param_2 == 0) {
      local_10 = *(undefined4 *)(param_1 + 0xa4);
      local_c = 0;
      local_8 = param_1 + 0xa8;
      local_18 = 0x14;
      if (*(int *)(param_1 + 0x38) < 10) {
        local_14 = *(uint *)(param_1 + 200) & 0xfffffffb | 8;
      }
      else {
        local_14 = *(uint *)(param_1 + 200) & 0xfffffff7;
      }
      iVar3 = (**(code **)(*DAT_006fed6c + 0xc))(DAT_006fed6c,&local_18,param_1 + 0x80,0);
      if (iVar3 != 0) goto LAB_005f9357;
      _DAT_006fed50 = _DAT_006fed50 + 1;
    }
    else {
      if (*(int *)(param_1 + 0x38) < 10) {
        *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffb | 8;
      }
      else {
        *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffff7;
      }
      iVar3 = (**(code **)(*DAT_006fed6c + 0xc))(DAT_006fed6c,param_2,param_1 + 0x80,0);
      if (iVar3 != 0) {
LAB_005f9357:
        piVar1 = *(int **)(param_1 + 0x80);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          _DAT_006fed5c = _DAT_006fed5c + 1;
          *(int *)(param_1 + 0x80) = 0;
        }
        return 0;
      }
      _DAT_006fed4c = _DAT_006fed4c + 1;
    }
  }
  return 1;
}

