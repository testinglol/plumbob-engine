
void FUN_00434ec8(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar3 = extraout_ECX;
  do {
    if (iVar3 == 0) {
      **(undefined4 **)(unaff_EBP + 8) = 0xffffffff;
      **(undefined4 **)(unaff_EBP + 0xc) = 0;
LAB_00434f6d:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    if ((((*(short *)(iVar3 + 0x8e) == 0) && ((*(ushort *)(iVar3 + 0x5a) & 4) == 0)) &&
        (sVar1 = *(short *)(*(int *)(iVar3 + 0x118) + 0x12), sVar1 != 2)) &&
       ((sVar1 != 9 && (*(int *)(iVar3 + 0x184) != -1)))) {
      uVar2 = *(uint *)(iVar3 + 0x184);
      *(char *)(unaff_EBP + -0x10) = (char)uVar2;
      sVar1 = *(short *)(iVar3 + 0x4c);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar3 = (int)sVar1 / 2;
      if (0 < iVar3) {
        *(undefined1 *)(unaff_EBP + -0x10) = (&DAT_006efc6c)[(uVar2 & 0xff) + iVar3 * 0x100];
      }
      **(uint **)(unaff_EBP + 8) = (uint)*(byte *)(unaff_EBP + -0x10);
      uVar4 = FUN_0045774e();
      **(undefined4 **)(unaff_EBP + 0xc) = uVar4;
      goto LAB_00434f6d;
    }
    iVar3 = FUN_004328d2(0);
  } while( true );
}

