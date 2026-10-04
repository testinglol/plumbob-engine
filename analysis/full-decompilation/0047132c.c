
void FUN_0047132c(void)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  int extraout_ECX;
  uint uVar7;
  int iVar8;
  int unaff_EBP;
  char *_Str;
  char *pcVar9;
  
  FUN_00634c24();
  uVar1 = *(undefined1 *)(extraout_ECX + 0x5d);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0xd) = uVar1;
  if (*(char *)(unaff_EBP + 0x10) != -1) {
    *(char *)(unaff_EBP + -0xd) = *(char *)(unaff_EBP + 0x10);
  }
  iVar2 = *(int *)(extraout_ECX + 0x6c);
  iVar8 = *(char *)(unaff_EBP + -0xd) * 0xc;
  uVar3 = *(uint *)(unaff_EBP + 8);
  if ((uVar3 <= (*(int *)(iVar8 + 4 + iVar2) - *(int *)(iVar8 + iVar2)) / 0xc + 1U) &&
     (0 < (int)uVar3)) {
    if (uVar3 == (*(int *)(iVar8 + 4 + iVar2) - *(int *)(iVar8 + iVar2)) / 0xc + 1U) {
      *(undefined1 *)(unaff_EBP + -0x18) = 0xff;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004716b8(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    iVar2 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x6c);
    *(uint *)(unaff_EBP + 8) = uVar3 * 0xc;
    iVar2 = *(int *)(*(int *)(iVar8 + iVar2) + -0xc + uVar3 * 0xc);
    if (iVar2 != 0) {
      FUN_006321f0(iVar2);
    }
    _Str = *(char **)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
    if (_Str != (char *)0x0) {
      sVar5 = _strlen(_Str);
      *(size_t *)(unaff_EBP + 0x10) = sVar5;
    }
    uVar3 = *(uint *)(unaff_EBP + 0x10);
    pcVar6 = operator_new(uVar3 + 1);
    pcVar9 = pcVar6;
    for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)_Str;
      _Str = _Str + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar7 = uVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar9 = *_Str;
      _Str = _Str + 1;
      pcVar9 = pcVar9 + 1;
    }
    iVar2 = *(int *)(unaff_EBP + -0x14);
    pcVar6[uVar3] = '\0';
    iVar4 = *(int *)(unaff_EBP + 8);
    *(char **)(*(int *)(iVar8 + *(int *)(iVar2 + 0x6c)) + -0xc + iVar4) = pcVar6;
    *(undefined1 *)(*(int *)(iVar8 + *(int *)(iVar2 + 0x6c)) + -4 + iVar4) =
         *(undefined1 *)(unaff_EBP + -0xd);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

