
void FUN_004fc1e5(void)

{
  int *piVar1;
  char *_Str;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  int extraout_ECX;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  iVar5 = *(int *)(DAT_006e486c + 0x28);
  *(int *)(unaff_EBP + -0x1c) = iVar5;
  iVar2 = *(int *)(iVar5 + 0x1280);
  iVar5 = *(int *)(iVar5 + 0x127c);
  *(int *)(unaff_EBP + -0x18) = iVar5;
  iVar7 = *(int *)(extraout_ECX + 300);
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  if (((iVar2 - iVar5) / 0x4c != iVar7) &&
     (iVar2 = (iVar2 - *(int *)(unaff_EBP + -0x18)) / 0x4c, *(int *)(extraout_ECX + 300) = iVar2,
     iVar5 = extraout_ECX, iVar7 < iVar2)) {
    do {
      iVar2 = *(int *)(iVar5 + 300);
      *(int *)(unaff_EBP + -0x14) = iVar7 + 5;
      if (iVar2 <= iVar7 + 5) {
        *(int *)(unaff_EBP + -0x14) = iVar2;
      }
      pvVar3 = operator_new(0x148);
      *(void **)(unaff_EBP + -0x18) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
      else {
        uVar4 = FUN_00523434();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00523771(&DAT_006f27f0);
      FUN_00523be3(&DAT_006f27e0);
      FUN_005d48d9();
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (iVar7 < *(int *)(unaff_EBP + -0x14)) {
        iVar5 = *(int *)(unaff_EBP + -0x14) - iVar7;
        iVar2 = iVar7 * 0x4c;
        *(int *)(unaff_EBP + -0x18) = iVar5;
        iVar7 = iVar7 + iVar5;
        do {
          _Str = *(char **)(iVar2 + 4 + *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x127c));
          *(char **)(unaff_EBP + -0x14) = _Str;
          sVar6 = _strlen(_Str);
          FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x14),sVar6 + *(int *)(unaff_EBP + -0x14));
          sVar6 = _strlen(&DAT_006c08dc);
          FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar6);
          iVar2 = iVar2 + 0x4c;
          piVar1 = (int *)(unaff_EBP + -0x18);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
        iVar5 = *(int *)(unaff_EBP + -0x20);
      }
      FUN_00523be3(unaff_EBP + -0x2c);
      uVar4 = FUN_005e50fa(3);
      FUN_0052386b(uVar4,0);
      FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    } while (iVar7 < *(int *)(iVar5 + 300));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

