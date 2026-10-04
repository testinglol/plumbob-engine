
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004373ae(void)

{
  char *_Str;
  undefined4 *puVar1;
  short sVar2;
  short sVar3;
  size_t sVar4;
  int unaff_EBP;
  int iVar5;
  bool bVar6;
  
  FUN_00634c24();
  bVar6 = DAT_006c2973 == '\0';
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  if (bVar6) {
    *(undefined4 *)(unaff_EBP + -0x28) = 0x7fffffff;
    *(undefined4 *)(unaff_EBP + -0x24) = 0x7fffffff;
    *(undefined4 *)(unaff_EBP + -0x20) = 0x80000000;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x80000000;
  }
  else {
    _Str = *(char **)(unaff_EBP + 0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar4 = _strlen(_Str);
    iVar5 = _DAT_006c2aa0;
    *(short *)(unaff_EBP + -0x18) =
         (short)*(undefined4 *)(unaff_EBP + 0x10) -
         (short)(*(int *)(unaff_EBP + 0x1c) << (*(char *)(unaff_EBP + 0x14) + 1U & 0x1f));
    *(short *)(unaff_EBP + -0x14) = (short)iVar5 + 4 + (short)*(undefined4 *)(unaff_EBP + -0x18);
    sVar3 = (short)((DAT_006c2aa2 + 1) * (short)sVar4 + 6) / 2;
    sVar2 = (short)*(undefined4 *)(unaff_EBP + 0xc);
    *(short *)(unaff_EBP + -0x12) = sVar2 + sVar3;
    *(short *)(unaff_EBP + -0x16) = sVar2 - sVar3;
    FUN_004374f5(unaff_EBP + -0x18,0xff);
    iVar5 = _DAT_006c2aa0 + 2 + *(int *)(unaff_EBP + -0x18);
    FUN_00464479(unaff_EBP + -0x20,*(int *)(unaff_EBP + -0x16) + 3,*(int *)(unaff_EBP + -0x18) + 2,
                 CONCAT22((short)((uint)iVar5 >> 0x10),DAT_006c2aa2 + *(short *)(unaff_EBP + -0x16))
                 + 3,iVar5);
    for (iVar5 = 0; iVar5 < (int)sVar4; iVar5 = iVar5 + 1) {
      *(char *)(unaff_EBP + 0x14) = _Str[iVar5];
      FUN_004375cb(*(undefined4 *)(unaff_EBP + -0x1e),*(undefined4 *)(unaff_EBP + -0x20),
                   *(undefined4 *)(unaff_EBP + 0x14));
      FUN_004643bc(unaff_EBP + -0x20,DAT_006c2aa2 + 1,0);
    }
    *(int *)(unaff_EBP + -0x24) = (int)*(short *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(unaff_EBP + -0x14);
    *(int *)(unaff_EBP + -0x28) = (int)*(short *)(unaff_EBP + -0x16);
    *(int *)(unaff_EBP + -0x20) = (int)*(short *)(unaff_EBP + -0x12);
  }
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar1 = *(undefined4 *)(unaff_EBP + -0x28);
  puVar1[1] = *(undefined4 *)(unaff_EBP + -0x24);
  puVar1[2] = *(undefined4 *)(unaff_EBP + -0x20);
  puVar1[3] = *(undefined4 *)(unaff_EBP + -0x1c);
  return;
}

