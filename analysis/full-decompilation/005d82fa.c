
undefined1 FUN_005d82fa(void)

{
  char cVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  int extraout_ECX;
  undefined1 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00412ab1(unaff_EBP + -0x5c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00401729();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined1 **)(unaff_EBP + -0x14) = &stack0xfffffe60;
  *(undefined1 **)(unaff_EBP + -0x14) = &stack0xfffffe5c;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00602902(&stack0xfffffe5c);
  FUN_005d8ced(unaff_EBP + -0x50);
  pvVar2 = FindFirstFileA(*(LPCSTR *)(unaff_EBP + -0x4c),(LPWIN32_FIND_DATAA)(unaff_EBP + -0x19c));
  *(HANDLE *)(unaff_EBP + -0x14) = pvVar2;
  if (pvVar2 == (HANDLE)0xffffffff) {
    uVar4 = 0;
LAB_005d8609:
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return uVar4;
  }
  *(int *)(unaff_EBP + -0x28) = extraout_ECX;
  FUN_005d4bbf();
  if ((*(byte *)(unaff_EBP + -0x19c) & 0x10) == 0) goto LAB_005d843c;
  *(undefined4 *)(unaff_EBP + -0x18) = 4;
  FUN_005d4956();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  cVar1 = FUN_00460748();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  if (cVar1 == '\0') {
    FUN_005d4956();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    cVar1 = FUN_00460748();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    goto LAB_005d8429;
  }
LAB_005d83f3:
  cVar1 = *(char *)(extraout_ECX + 0x41);
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  do {
    if (cVar1 == '\0') goto LAB_005d844e;
    do {
      do {
        while( true ) {
          FUN_005d8c4c();
LAB_005d844e:
          BVar3 = FindNextFileA(*(HANDLE *)(unaff_EBP + -0x14),
                                (LPWIN32_FIND_DATAA)(unaff_EBP + -0x19c));
          if (BVar3 == 0) {
            FindClose(*(HANDLE *)(unaff_EBP + -0x14));
            if (((*(char *)(extraout_ECX + 0x40) != '\0') && (*(char *)(unaff_EBP + -0xe) == '\0'))
               && (cVar1 = FUN_00460748(), cVar1 != '\0')) {
              FUN_005d4956();
              *(undefined1 *)(unaff_EBP + -4) = 8;
              cVar1 = FUN_005d8a54();
              if (cVar1 == '\0') {
                FUN_005d499c();
                *(undefined4 *)(unaff_EBP + -0x18) = 4;
                FUN_005d8c2c();
              }
              *(undefined1 *)(unaff_EBP + -4) = 3;
              FUN_005b8770();
            }
            if (((*(char *)(extraout_ECX + 0x41) != '\0') && (*(char *)(unaff_EBP + -0xd) == '\0'))
               && (cVar1 = FUN_00460748(), cVar1 != '\0')) {
              FUN_005d4956();
              *(undefined1 *)(unaff_EBP + -4) = 9;
              FUN_005d4956();
              *(undefined1 *)(unaff_EBP + -4) = 10;
              cVar1 = FUN_005d8a54();
              *(undefined1 *)(unaff_EBP + -4) = 9;
              FUN_005b8770();
              if (cVar1 == '\0') {
                FUN_005d499c();
                *(undefined4 *)(unaff_EBP + -0x18) = 4;
                FUN_005d8c2c();
              }
              *(undefined1 *)(unaff_EBP + -4) = 3;
              FUN_005b8770();
            }
            uVar4 = 1;
            goto LAB_005d8609;
          }
          FUN_005d4bbf();
          if ((*(byte *)(unaff_EBP + -0x19c) & 0x10) != 0) break;
LAB_005d843c:
          *(undefined4 *)(unaff_EBP + -0x18) = 8;
        }
        *(undefined4 *)(unaff_EBP + -0x18) = 4;
        if (*(char *)(unaff_EBP + -0xd) == '\0') {
          FUN_005d4956();
          *(undefined1 *)(unaff_EBP + -4) = 6;
          cVar1 = FUN_00460748();
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005b8770();
          if (cVar1 != '\0') goto LAB_005d83f3;
        }
      } while (*(char *)(unaff_EBP + -0xe) != '\0');
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      cVar1 = FUN_00460748();
      *(undefined1 *)(unaff_EBP + -4) = 3;
LAB_005d8429:
      FUN_005b8770();
    } while (cVar1 == '\0');
    cVar1 = *(char *)(extraout_ECX + 0x40);
    *(undefined1 *)(unaff_EBP + -0xe) = 1;
  } while( true );
}

