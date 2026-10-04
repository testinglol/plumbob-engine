
void FUN_004c922e(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  ushort *puVar6;
  int *piVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_004a3bab();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 1;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x310;
  piVar7 = (int *)(*(int *)(unaff_EBP + 8) + 8);
  do {
    pvVar4 = operator_new(0x48);
    *(void **)(unaff_EBP + 8) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004a3cc0(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x20));
    }
    uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *piVar7 = iVar5;
    iVar5 = FUN_004c8f7a(uVar3);
    if ((iVar5 != 0) &&
       (puVar6 = (ushort *)(*(int *)(*(int *)(iVar5 + 0xc) + 0xc) + *(int *)(iVar5 + 0xc)),
       puVar6 != (ushort *)0x0)) {
      pvVar4 = _malloc((uint)puVar6[1] * (uint)*puVar6);
      uVar1 = puVar6[1];
      uVar2 = *puVar6;
      *(void **)(unaff_EBP + 8) = pvVar4;
      _memset(pvVar4,0xff,(uint)uVar1 * (uint)uVar2);
      uVar1 = *puVar6;
      puVar6[5] = 0xff;
      FUN_004c166f(puVar6,*(undefined4 *)(unaff_EBP + 8),(uint)uVar1);
      iVar5 = *piVar7;
      *(undefined4 *)(iVar5 + 0x40) = *(undefined4 *)(unaff_EBP + 8);
      *(uint *)(iVar5 + 0x44) = (uint)uVar1;
    }
    iVar5 = FUN_004c8f7a(*(int *)(unaff_EBP + -0x18) + -0x10);
    if ((iVar5 != 0) &&
       (puVar6 = (ushort *)(*(int *)(*(int *)(iVar5 + 0xc) + 0xc) + *(int *)(iVar5 + 0xc)),
       puVar6 != (ushort *)0x0)) {
      pvVar4 = _malloc((uint)puVar6[1] * (uint)*puVar6);
      _memset(pvVar4,(int)(short)puVar6[5],(uint)puVar6[1] * (uint)*puVar6);
      uVar1 = *puVar6;
      *(uint *)(unaff_EBP + -0x24) = (uint)uVar1;
      *(void **)(unaff_EBP + -0x28) = pvVar4;
      FUN_004c166f(puVar6,pvVar4,(uint)uVar1);
      FUN_004c941c(puVar6,*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x24));
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_004a3e69(unaff_EBP + 0xb,unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    iVar5 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + -0x18));
    if ((iVar5 != 0) &&
       (puVar6 = (ushort *)(*(int *)(*(int *)(iVar5 + 0xc) + 0xc) + *(int *)(iVar5 + 0xc)),
       puVar6 != (ushort *)0x0)) {
      pvVar4 = _malloc((uint)*puVar6 * (uint)puVar6[1]);
      _memset(pvVar4,(int)(short)puVar6[5],(uint)*puVar6 * (uint)puVar6[1]);
      uVar1 = *puVar6;
      *(uint *)(unaff_EBP + -0x2c) = (uint)uVar1;
      *(void **)(unaff_EBP + -0x30) = pvVar4;
      FUN_004c166f(puVar6,pvVar4,(uint)uVar1);
      FUN_004c941c(puVar6,*(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x2c));
      *(undefined1 *)(unaff_EBP + -0xd) = 0x10;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_004a3e69(unaff_EBP + -0xd,unaff_EBP + -0x30);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x100;
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0x20;
    piVar7 = piVar7 + -1;
  } while (*(int *)(unaff_EBP + -0x1c) < 0x201);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

