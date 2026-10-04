
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ff397(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  _DAT_006f2a40 = (**(code **)(*piVar1 + 0x38))(0xa6,0xb4,0xb4);
  _DAT_006f2a40 = _DAT_006f2a40 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0xc3,0xcd,0xcd);
  DAT_006f2a44 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0xff,0xff,0xff);
  DAT_006f2a48 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0,0xff,0xff);
  DAT_006f2a4c = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0x40,0x5d,0x5f);
  DAT_006f2a50 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0,0,0x52);
  DAT_006f2a54 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0,0,0x4a);
  DAT_006f2a58 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0xd1,0,0);
  DAT_006f2a5c = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0,0xca,0x39);
  DAT_006f2a60 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0xff,0,0xff);
  DAT_006f2a64 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0,0x32,0);
  DAT_006f2a68 = uVar2 & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  _DAT_006f2a6c = (**(code **)(*piVar1 + 0x38))(0x88,0x2e,0x2f);
  _DAT_006f2a6c = _DAT_006f2a6c & 0xffff;
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar2 = (**(code **)(*piVar1 + 0x38))(0x20,0x93,0x4c);
  DAT_006f2a70 = uVar2 & 0xffff;
  local_1c = DAT_006f2a48;
  local_24 = DAT_006f2a44;
  local_20 = DAT_006f2a4c;
  local_18 = DAT_006f2a4c;
  local_14 = DAT_006f2a50;
  local_10 = DAT_006f2a50;
  piVar1 = (int *)FUN_005e7743();
  (**(code **)(*piVar1 + 0x4c))(6,&local_24);
  local_1c = DAT_006f2a44;
  local_18 = DAT_006f2a4c;
  local_14 = DAT_006f2a48;
  local_10 = DAT_006f2a50;
  piVar1 = (int *)FUN_005e7743();
  (**(code **)(*piVar1 + 0x4c))(4,&local_1c);
  local_c = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  local_8 = 0;
  piVar1 = &DAT_006f2a74;
  do {
    piVar3 = (int *)(**(code **)(*local_c + 0x10))(1,local_8,0,0);
    *piVar1 = (int)piVar3;
    if ((piVar3 == (int *)0x0) ||
       (iVar4 = (**(code **)(*piVar3 + 0x18))(), uVar2 = DAT_006f2a44, iVar4 != local_8)) {
      if (*piVar1 != 0) {
        (**(code **)(*local_c + 0x14))(*piVar1);
        *piVar1 = 0;
      }
      (&DAT_006f2a28)[local_8] = 0;
    }
    else {
      (&DAT_006f2a28)[local_8] = 1;
      (**(code **)(*(int *)*piVar1 + 0x20))(uVar2);
    }
    local_8 = local_8 + 1;
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6f2ad0);
  DAT_006f2ad0 = (int *)(**(code **)(*local_c + 0x10))(1,0xc,0x10,0);
  if (DAT_006f2ad0 != (int *)0x0) {
    (**(code **)(*DAT_006f2ad0 + 0x20))(DAT_006f2a44);
  }
  iVar4 = 0;
  piVar1 = &DAT_006f2a78;
  while ((piVar1[-1] != 0 || (*piVar1 == 0))) {
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + 1;
    if (0x6f2acf < (int)piVar1) {
LAB_004ff691:
      piVar1 = &DAT_006f2a74;
      do {
        if ((piVar1 != &DAT_006f2a74) && (*piVar1 == 0)) {
          *piVar1 = piVar1[-1];
        }
        piVar1 = piVar1 + 1;
      } while ((int)piVar1 < 0x6f2ad0);
      return;
    }
  }
  if (-1 < iVar4) {
    iVar5 = iVar4 + 1;
    puVar6 = &DAT_006f2a74 + iVar4;
    do {
      *puVar6 = (&DAT_006f2a78)[iVar4];
      puVar6 = puVar6 + -1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  goto LAB_004ff691;
}

