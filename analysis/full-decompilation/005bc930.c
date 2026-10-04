
char FUN_005bc930(void)

{
  int *piVar1;
  int *piVar2;
  char *_Str1;
  int iVar3;
  size_t sVar4;
  char *_Str2;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  char cVar6;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 8);
  piVar1 = (int *)(extraout_ECX + 4);
  iVar3 = (**(code **)(*piVar2 + 0x1c))();
  if (*(int *)(extraout_ECX + 8) - *piVar1 == iVar3) {
    if (*(char *)(unaff_EBP + 0xc) != '\0') {
      _Str1 = (char *)*piVar1;
      sVar4 = *(int *)(extraout_ECX + 8) - (int)_Str1;
      _Str2 = (char *)(**(code **)(*piVar2 + 0x18))();
      iVar3 = _strncmp(_Str1,_Str2,sVar4);
      cVar6 = iVar3 == 0;
      goto LAB_005bca67;
    }
    FUN_005bd6b3(-(uint)(extraout_ECX != 0) & (uint)piVar1,0,0xffffffff,unaff_EBP + 0xf);
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    iVar3 = *(int *)(extraout_ECX + 8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar3 = iVar3 - *piVar1;
    uVar5 = (**(code **)(*piVar2 + 0x18))(iVar3);
    FUN_005bddb3(uVar5,iVar3);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005bc7c7();
    FUN_005bc7c7();
    sVar4 = *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x1c);
    if (sVar4 == *(int *)(unaff_EBP + -0x2c) - *(int *)(unaff_EBP + -0x30)) {
      iVar3 = _memcmp(*(void **)(unaff_EBP + -0x1c),*(void **)(unaff_EBP + -0x30),sVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      cVar6 = '\x01' - (iVar3 != 0);
      *(undefined ***)(unaff_EBP + -0x34) = &PTR_LAB_0066933c;
      FUN_00401729();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
      FUN_00401729();
      goto LAB_005bca67;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x34) = &PTR_LAB_0066933c;
    FUN_00401729();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  cVar6 = '\0';
LAB_005bca67:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar6;
}

