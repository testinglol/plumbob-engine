
undefined4 FUN_00594536(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_c;
  int local_8;
  
  cVar1 = FUN_005b9095(&local_8);
  if (cVar1 == '\0') {
LAB_005945c3:
    uVar3 = 0;
  }
  else {
    iVar4 = 0;
    if (0 < local_8) {
      do {
        cVar1 = FUN_005b9095(&local_c);
        if (cVar1 == '\0') goto LAB_005945c3;
        puVar2 = operator_new(0x10);
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
        }
        cVar1 = FUN_0059411c(param_1);
        if (cVar1 == '\0') {
          if (puVar2 != (undefined4 *)0x0) {
            FUN_00594235();
            FUN_006321f0(puVar2);
          }
          goto LAB_005945c3;
        }
        FUN_00594713(local_c,puVar2);
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_8);
    }
    uVar3 = 1;
  }
  return uVar3;
}

