
undefined4 FUN_005bca88(void)

{
  int *piVar1;
  int *piVar2;
  char *_Str1;
  undefined4 uVar3;
  uint uVar4;
  char *_Str2;
  int iVar5;
  undefined4 uVar6;
  size_t *psVar7;
  int extraout_ECX;
  uint uVar8;
  int unaff_EBP;
  size_t _MaxCount;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 8);
  uVar3 = (**(code **)(*piVar2 + 0x1c))();
  piVar1 = (int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + 8) = uVar3;
  uVar4 = *(int *)(extraout_ECX + 8) - *piVar1;
  *(uint *)(unaff_EBP + -0x10) = uVar4;
  psVar7 = (size_t *)(unaff_EBP + 8);
  if (uVar4 <= *(uint *)(unaff_EBP + 8)) {
    psVar7 = (size_t *)(unaff_EBP + -0x10);
  }
  _MaxCount = *psVar7;
  if (*(char *)(unaff_EBP + 0xc) == '\0') {
    FUN_005bd6b3(-(uint)(extraout_ECX != 0) & (uint)piVar1,0,0xffffffff,unaff_EBP + 0xf);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined ***)(unaff_EBP + -0x24) = &PTR_LAB_0066933c;
    iVar5 = *piVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar3 = (**(code **)(iVar5 + 0x1c))();
    uVar6 = (**(code **)(*piVar2 + 0x18))(uVar3);
    FUN_005bddb3(uVar6,uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005bc7c7();
    FUN_005bc7c7();
    uVar4 = *(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34);
    uVar8 = *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x20);
    *(uint *)(unaff_EBP + 8) = uVar4;
    *(uint *)(unaff_EBP + -0x10) = uVar8;
    psVar7 = (size_t *)(unaff_EBP + 8);
    if (uVar8 <= uVar4) {
      psVar7 = (size_t *)(unaff_EBP + -0x10);
    }
    iVar5 = _memcmp(*(void **)(unaff_EBP + -0x20),*(void **)(unaff_EBP + -0x34),*psVar7);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + 8) = iVar5;
    *(undefined ***)(unaff_EBP + -0x38) = &PTR_LAB_0066933c;
    FUN_00401729();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x24) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    _Str1 = (char *)*piVar1;
    _Str2 = (char *)(**(code **)(*piVar2 + 0x18))();
    iVar5 = _strncmp(_Str1,_Str2,_MaxCount);
    *(int *)(unaff_EBP + 8) = iVar5;
  }
  if (*(int *)(unaff_EBP + 8) == 0) {
    iVar5 = (**(code **)(*piVar2 + 0x1c))();
    *(int *)(unaff_EBP + 8) = (*(int *)(extraout_ECX + 8) - *piVar1) - iVar5;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

