
undefined4 FUN_005945c7(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_c [4];
  int local_8;
  
  cVar1 = FUN_005b9095(&local_8);
  if (cVar1 == '\0') {
LAB_00594610:
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    if (0 < local_8) {
      do {
        cVar1 = FUN_005b9095(local_c);
        if (cVar1 == '\0') goto LAB_00594610;
        cVar1 = FUN_00594196(param_1);
        if (cVar1 == '\0') goto LAB_00594610;
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_8);
    }
    uVar2 = 1;
  }
  return uVar2;
}

