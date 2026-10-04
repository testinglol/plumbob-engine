
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00542d15(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  SHORT SVar6;
  undefined4 uVar7;
  void *pvVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar5 = (**(code **)(*extraout_ECX + 200))();
  if (cVar5 == '\0') {
    thunk_FUN_005dbf32();
    if (DAT_006f4f68 == 0) {
      FUN_005a5631(0x139b,&DAT_006f4f68,4);
    }
    SVar6 = GetKeyState(0x10);
    if (SVar6 < 0) {
      if (DAT_006f4f6c == (int *)0x0) {
        FUN_005a5631(0x139d,&DAT_006f4f6c,4);
        if (DAT_006f4f6c != (int *)0x0) {
          (**(code **)(*DAT_006f4f6c + 0x68))(DAT_006f2a64);
        }
      }
    }
    else {
      DAT_006f4f6c = (int *)0x0;
    }
    extraout_ECX[0x78] = *(int *)(DAT_006f4f68 + 0x20) / 3;
    (**(code **)(*extraout_ECX + 0x19c))(DAT_006f4f68,1,3);
    extraout_ECX[0x3d] = 1;
    extraout_ECX[0x3e] = 1;
    FUN_005e4a66(1);
    piVar9 = extraout_ECX + 0x65;
    *(undefined4 *)(unaff_EBP + -0x10) = 8;
    do {
      if (*piVar9 == 0) {
        pvVar8 = operator_new(0x198);
        *(void **)(unaff_EBP + -0x14) = pvVar8;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar8 == (void *)0x0) {
          puVar10 = (undefined4 *)0x0;
        }
        else {
          FUN_005e372a();
          puVar10 = *(undefined4 **)(unaff_EBP + -0x14);
          *puVar10 = &PTR_FUN_0066f5b8;
          _DAT_006f4f64 = _DAT_006f4f64 + 1;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *piVar9 = (int)puVar10;
        if (puVar10 != (undefined4 *)0x0) {
          FUN_005e4a66(1);
          (**(code **)(*(int *)*piVar9 + 0x60))(0,0,0x2d,extraout_ECX[0x78]);
          iVar2 = extraout_ECX[0x78];
          iVar3 = *piVar9;
          *(undefined4 *)(iVar3 + 0x144) = 0;
          *(int *)(iVar3 + 0x148) = (iVar2 + -0x2d) / 2 + -5;
          (**(code **)(*extraout_ECX + 0x20))(*piVar9);
        }
      }
      piVar9 = piVar9 + 1;
      piVar1 = (int *)(unaff_EBP + -0x10);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    iVar4 = DAT_006f4f5c;
    iVar3 = extraout_ECX[0x78];
    iVar2 = DAT_006f4f58 + 0x180;
    *(int *)(unaff_EBP + -0x38) = DAT_006f4f58;
    *(undefined4 *)(unaff_EBP + -0x30) = 0x30;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0x30;
    *(undefined4 *)(unaff_EBP + -0x20) = 0x30;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x30;
    *(int *)(unaff_EBP + -0x34) = iVar4;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    *(int *)(unaff_EBP + -0x28) = iVar2;
    *(int *)(unaff_EBP + -0x24) = iVar3 + iVar4;
    FUN_004ebf01(extraout_ECX + 0x65,8);
    pvVar8 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x14) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar8 == (void *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x79] = (int)piVar9;
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 0x1a0))(s_The_Symptoms_006cd5f0);
      (**(code **)(*(int *)(extraout_ECX[0x79] + 0xd4) + 0x18))(DAT_006f2aa4);
      (**(code **)(*(int *)extraout_ECX[0x79] + 0x90))(0x10,0);
      (**(code **)(*(int *)(extraout_ECX[0x79] + 0xd4) + 0x14))(0);
      FUN_005e9fa4(DAT_006f2a54);
      *(code **)(extraout_ECX[0x79] + 8) = FUN_00543337;
      (**(code **)(*(int *)(extraout_ECX[0x79] + 0xd4) + 0x1c))(0);
      (**(code **)(*(int *)(extraout_ECX[0x79] + 0xd4) + 0xc))(2,0);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x79]);
      (**(code **)(*(int *)(extraout_ECX[0x79] + 0xd4) + 0x1c))(0);
      (**(code **)(*(int *)(extraout_ECX[0x79] + 0xd4) + 0x20))(0,0);
      (*(code *)**(undefined4 **)(extraout_ECX[0x79] + 0xd4))();
    }
    pvVar8 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x14) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar8 == (void *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x7a] = (int)piVar9;
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 0x1a0))(s__999_999_999_006cd5e0);
      (**(code **)(*(int *)(extraout_ECX[0x7a] + 0xd4) + 0x18))(DAT_006f2a9c);
      (**(code **)(*(int *)extraout_ECX[0x7a] + 0x90))(0x10,0);
      (**(code **)(*(int *)(extraout_ECX[0x7a] + 0xd4) + 0x14))(0);
      FUN_005e9fa4(DAT_006f2a54);
      *(code **)(extraout_ECX[0x7a] + 8) = FUN_00543337;
      (**(code **)(*(int *)(extraout_ECX[0x7a] + 0xd4) + 0x1c))(3);
      (**(code **)(*(int *)(extraout_ECX[0x7a] + 0xd4) + 0xc))(2,0);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x7a]);
      (*(code *)**(undefined4 **)(extraout_ECX[0x7a] + 0xd4))();
      puVar10 = &DAT_006f4f38;
      if ((char)extraout_ECX[0x7d] == '\0') {
        puVar10 = &DAT_006f4f48;
      }
      FUN_004cb21d(*puVar10,puVar10[1]);
    }
    pvVar8 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x14) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (pvVar8 == (void *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x7b] = (int)piVar9;
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 0x1a0))(&DAT_006c839c);
      (**(code **)(*(int *)(extraout_ECX[0x7b] + 0xd4) + 0x18))(DAT_006f2a9c);
      (**(code **)(*(int *)extraout_ECX[0x7b] + 0x90))(0x10,0);
      (**(code **)(*(int *)(extraout_ECX[0x7b] + 0xd4) + 0x14))(0);
      FUN_005e9fa4(DAT_006f2a54);
      *(code **)(extraout_ECX[0x7b] + 8) = FUN_00543337;
      (**(code **)(*(int *)(extraout_ECX[0x7b] + 0xd4) + 0x1c))(3);
      (**(code **)(*(int *)(extraout_ECX[0x7b] + 0xd4) + 0xc))(2,0);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x7b]);
      (*(code *)**(undefined4 **)(extraout_ECX[0x7b] + 0xd4))();
      FUN_004cb21d(DAT_006f4f20,DAT_006f4f24);
      if ((char)extraout_ECX[0x7d] == '\0') {
        (**(code **)(*(int *)extraout_ECX[0x7b] + 0x98))();
      }
    }
    pvVar8 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x14) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    if (pvVar8 == (void *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x7c] = (int)piVar9;
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 0x1a0))(&DAT_006cd5dc);
      (**(code **)(*(int *)(extraout_ECX[0x7c] + 0xd4) + 0x18))(DAT_006f2a9c);
      (**(code **)(*(int *)extraout_ECX[0x7c] + 0x90))(0x10,0);
      (**(code **)(*(int *)(extraout_ECX[0x7c] + 0xd4) + 0x14))(0);
      FUN_005e9fa4(DAT_006f2a54);
      *(code **)(extraout_ECX[0x7c] + 8) = FUN_00543337;
      (**(code **)(*(int *)(extraout_ECX[0x7c] + 0xd4) + 0x1c))(3);
      (**(code **)(*(int *)(extraout_ECX[0x7c] + 0xd4) + 0xc))(2,0);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x7c]);
      (*(code *)**(undefined4 **)(extraout_ECX[0x7c] + 0xd4))();
      puVar10 = &DAT_006f4f30;
      if ((char)extraout_ECX[0x7d] == '\0') {
        puVar10 = &DAT_006f4f40;
      }
      FUN_004cb21d(*puVar10,puVar10[1]);
    }
    uVar7 = 1;
  }
  else {
    uVar7 = thunk_FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

