
undefined4 FUN_004b7bc1(void)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_c;
  undefined2 *local_8;
  
  FUN_005a5631(0x1130,&DAT_006f065c,3);
  iVar5 = 0;
  if ((DAT_006f065c != 0) && (FUN_005a5631(0x1131,&DAT_006f0660,3), DAT_006f0660 != 0)) {
    piVar1 = *(int **)(DAT_006f065c + 0x10);
    if (piVar1 != (int *)0x0) {
      iVar2 = *(int *)(DAT_006e486c + 0x34);
      iVar4 = (**(code **)(*piVar1 + 0xc))();
      if (0 < iVar4) {
        local_8 = &DAT_006f045c;
        do {
          (**(code **)(*piVar1 + 0x14))(iVar5,&local_c);
          if (iVar2 == 1) {
            uVar3 = FUN_0049f1f4();
          }
          else {
            uVar3 = FUN_0049f21b(local_c);
          }
          iVar5 = iVar5 + 1;
          *local_8 = uVar3;
          local_8 = local_8 + 1;
          iVar4 = (**(code **)(*piVar1 + 0xc))();
        } while (iVar5 < iVar4);
      }
    }
    return 1;
  }
  return 0;
}

