
void __fastcall FUN_004a893f(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  float10 fVar5;
  
  *(uint *)(unaff_EBP + -0x10) =
       (uint)CONCAT11(*(undefined1 *)(param_1 + 0x48),*(undefined1 *)(param_1 + 0x49));
  FUN_00464a5e(unaff_EBP + -0x10,1);
  uVar2 = *(uint *)(unaff_EBP + -0x10);
  *(undefined1 *)(param_1 + 0x4e) = 1;
  cVar1 = *(char *)(unaff_EBP + -0x10);
  *(bool *)(param_1 + 0x48) = (uVar2 & 0xffffff00) != 0;
  *(bool *)(param_1 + 0x49) = cVar1 != '\0';
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (*(char *)(param_1 + 0x49) != '\0') {
      *(undefined1 *)(param_1 + 0x48) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x49) = 0;
  }
  FUN_00464a5e(&DAT_006f0088,1);
  FUN_00464a5e(&DAT_006f0080,1);
  iVar3 = FUN_00464a5e(&DAT_006f0084,1);
  if (8 < *(int *)(unaff_EBP + 0xc)) {
    *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(DAT_006e54d8 + 0x84);
    FUN_00464973(unaff_EBP + 8,1);
    DAT_006f008c = (int)*(short *)(unaff_EBP + 8);
    iVar3 = FUN_00479318(DAT_006f008c,1);
  }
  if (*(int *)(unaff_EBP + 0xc) < 0x1d) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  else {
    *(uint *)(unaff_EBP + 8) =
         CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(param_1 + 0x18));
    FUN_00464973(unaff_EBP + 8,1);
    iVar3 = (int)*(short *)(unaff_EBP + 8);
    *(int *)(param_1 + 0x18) = iVar3;
  }
  if (0x29 < *(int *)(unaff_EBP + 0xc)) {
    *(uint *)(unaff_EBP + 8) =
         CONCAT22((short)((uint)iVar3 >> 0x10),(ushort)*(byte *)(param_1 + 0x51));
    FUN_00464973(unaff_EBP + 8,1);
    *(bool *)(param_1 + 0x51) = *(short *)(unaff_EBP + 8) != 0;
  }
  if (0x30 < *(int *)(unaff_EBP + 0xc)) {
    fVar5 = (float10)FUN_0056f31a();
    *(float *)(unaff_EBP + 0xc) = (float)fVar5;
    FUN_00464b48(unaff_EBP + 0xc,1);
    FUN_0056f23d(*(undefined4 *)(unaff_EBP + 0xc));
    uVar4 = FUN_0056f3cd();
    FUN_005b870f(uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00464c84(unaff_EBP + -0x1c);
    FUN_0056f32e(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

