
undefined4 FUN_00594196(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  cVar1 = FUN_005b9095(&local_8);
  if (cVar1 == '\0') {
LAB_005941d7:
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    if (0 < local_8) {
      do {
        cVar1 = FUN_005b911f();
        if (cVar1 == '\0') goto LAB_005941d7;
        cVar1 = FUN_005b911f();
        if (cVar1 == '\0') goto LAB_005941d7;
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_8);
    }
    uVar2 = 1;
  }
  return uVar2;
}

