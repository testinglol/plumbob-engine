
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004d4529(void)

{
  undefined4 uVar1;
  float fVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 *puVar5;
  HDC hdc;
  int iVar6;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00668f84;
  extraout_ECX[1] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[0x23] = 0;
  puVar5 = (undefined4 *)FUN_005caed9();
  fVar2 = (float)_DAT_00668f78;
  extraout_ECX[5] = *puVar5;
  extraout_ECX[6] = puVar5[1];
  extraout_ECX[0x19] = ABS(fVar2);
  *(undefined1 *)(extraout_ECX + 9) = 0;
  *(undefined1 *)(extraout_ECX + 0x11) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x45) = 0;
  extraout_ECX[0x12] = 8;
  extraout_ECX[0x17] = 0x40a00000;
  extraout_ECX[0x18] = 0xc40ca000;
  extraout_ECX[0x1f] = *(undefined4 *)(DAT_006e486c + 4);
  extraout_ECX[0x20] = *(undefined4 *)(DAT_006f2a08 + 0x84);
  hdc = GetDC((HWND)0x0);
  *(HDC *)(unaff_EBP + -0x10) = hdc;
  iVar6 = GetDeviceCaps(hdc,8);
  *(int *)(unaff_EBP + -0x14) = iVar6;
  iVar6 = GetDeviceCaps(*(HDC *)(unaff_EBP + -0x10),10);
  ReleaseDC((HWND)0x0,*(HDC *)(unaff_EBP + -0x10));
  cVar3 = FUN_005caf08();
  if (cVar3 == '\0') {
    if ((*(int *)(unaff_EBP + -0x14) == extraout_ECX[5]) && (iVar6 == extraout_ECX[6])) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    *(undefined1 *)((int)extraout_ECX + 0x55) = uVar4;
  }
  else {
    *(undefined1 *)((int)extraout_ECX + 0x55) = 1;
  }
  if (*(char *)((int)extraout_ECX + 0x55) == '\0') {
    extraout_ECX[0x16] = 0x20;
    iVar6 = (**(code **)(*(int *)extraout_ECX[0x1f] + 0xc))();
    uVar1 = *(undefined4 *)(iVar6 + 0x14);
    extraout_ECX[7] = *(undefined4 *)(iVar6 + 0x10);
    extraout_ECX[8] = uVar1;
    *(undefined1 *)(extraout_ECX + 0x15) = 1;
  }
  else {
    extraout_ECX[0x16] = 5;
    extraout_ECX[7] = extraout_ECX[5];
    extraout_ECX[8] = extraout_ECX[6];
    *(undefined1 *)(extraout_ECX + 0x15) = 0;
  }
  extraout_ECX[0x1e] = 0;
  _memset(extraout_ECX + 0x1a,0,0x10);
  extraout_ECX[0x22] = 0;
  *(undefined1 *)(extraout_ECX + 0x24) = 0;
  iVar6 = FUN_004e609e();
  if (iVar6 != 0) {
    FUN_004e609e();
    uVar4 = FUN_004e6383();
    *(undefined1 *)((int)extraout_ECX + 0x91) = uVar4;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)((int)extraout_ECX + 0x92) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x93) = 0;
  return extraout_ECX;
}

