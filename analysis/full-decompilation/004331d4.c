
void FUN_004331d4(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  if (*(short *)(extraout_ECX[0x46] + 0x14) == 0) {
    FUN_00422d79(10,0,0);
  }
  iVar4 = extraout_ECX[0x3e];
  *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x3d] >> 4;
  iVar2 = extraout_ECX[0x13];
  iVar4 = iVar4 >> 4;
  *(int *)(unaff_EBP + -0x18) = iVar4;
  *(int *)(unaff_EBP + -0x1c) = (int)(short)iVar2;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -0x4c) = 0;
  FUN_004341a6(0);
  FUN_00434f7b();
  if (DAT_006e4870 != '\0') {
    FUN_00438fc0(unaff_EBP + -0x34,3);
    FUN_004a6af5(unaff_EBP + -0x34);
  }
  if (*(short *)((int)extraout_ECX + 0x6a) == 1) {
    iVar4 = extraout_ECX[0x3d];
    iVar2 = extraout_ECX[0x44];
    *(char *)(unaff_EBP + -0x10) = (char)(extraout_ECX[0x3e] >> 4);
    *(char *)(unaff_EBP + -0xf) = (char)(iVar4 >> 4);
    *(char *)(unaff_EBP + -0xe) = (char)iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004b52ba(unaff_EBP + -0x10,1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar4 = *(int *)(unaff_EBP + -0x18);
  }
  if ((*(ushort *)((int)extraout_ECX + 0x9a) & 0x400) != 0) {
    FUN_0040766a(0xf2,(int)(short)extraout_ECX[0x3c]);
  }
  *(undefined4 *)(unaff_EBP + -0x60) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
  FUN_00432664(unaff_EBP + -100);
  FUN_00432a70(unaff_EBP + -0x4c,1);
  *(undefined2 *)(extraout_ECX + 0x14) = 0xffff;
  *(undefined4 *)(unaff_EBP + -0x20) = 0xfffffff0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0xfffffff0;
  *(undefined2 *)((int)extraout_ECX + 0x4e) = 0;
  FUN_00433ef5(unaff_EBP + -0x24,1,0);
  *(byte *)((int)extraout_ECX + 0x5b) = *(byte *)((int)extraout_ECX + 0x5b) & 0xfe;
  FUN_00457da4();
  sVar1 = FUN_004561a0(0x1a);
  if (sVar1 != 0) {
    iVar2 = *(int *)(unaff_EBP + -0x1c) * 4;
    FUN_004336c1(extraout_ECX[0x37],*(int *)(&DAT_006c2924 + iVar2) + iVar4,
                 *(int *)(&DAT_006c2948 + iVar2) + *(int *)(unaff_EBP + -0x14),extraout_ECX[0x44]);
  }
  if (*(int *)(unaff_EBP + -0x58) != 0) {
    FUN_00422d79(9,0,0);
  }
  iVar2 = FUN_004573f9();
  if (*(short *)(*(int *)(iVar2 + 0x60) + 0x8a) == 6) {
    FUN_00433186(iVar4,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x44],0);
  }
  iVar4 = (**(code **)(*extraout_ECX + 0x2c))();
  if (iVar4 != 0) {
    piVar3 = (int *)(**(code **)(*extraout_ECX + 0x2c))();
    (**(code **)(*piVar3 + 0x54))(1);
  }
  if (*(char *)(unaff_EBP + 8) != '\0') {
    FUN_00447d6b(extraout_ECX);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

