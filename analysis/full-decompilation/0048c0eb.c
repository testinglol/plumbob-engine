
undefined4 __fastcall FUN_0048c0eb(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  piVar2 = (int *)FUN_0048c284();
  iVar3 = 0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x6c))(0);
    do {
      if ((int)(short)piVar2[0x13] == *(int *)(param_1 + 0x10)) break;
      (**(code **)(*piVar2 + 0x4c))(1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    if ((int)(short)piVar2[0x13] == *(int *)(param_1 + 0x10)) {
      iVar3 = 0;
      if ((*(short *)(param_1 + 0x14) != 0) &&
         (iVar3 = FUN_00407498((int)*(short *)(param_1 + 0x14)), iVar3 == 0)) {
        return 0;
      }
      local_c = *(int *)(param_1 + 4);
      local_8 = *(undefined4 *)(param_1 + 8);
      cVar1 = (**(code **)(*piVar2 + 0x60))
                        (&local_c,*(undefined4 *)(param_1 + 0xc),iVar3,
                         *(undefined4 *)(param_1 + 0x18));
      if (cVar1 != '\0') {
        (**(code **)(*piVar2 + 100))
                  (&local_c,*(undefined4 *)(param_1 + 0xc),iVar3,*(undefined4 *)(param_1 + 0x18));
        return 1;
      }
    }
  }
  return 0;
}

