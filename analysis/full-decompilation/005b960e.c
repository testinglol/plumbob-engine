
undefined1 FUN_005b960e(void)

{
  char cVar1;
  undefined1 uVar2;
  HANDLE hObject;
  undefined4 *puVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  
  FUN_00634c24();
  cVar1 = FUN_005b9bbe(*(undefined4 *)(unaff_EBP + 8),0);
  if (cVar1 == '\0') {
    FUN_005b8680();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b96fe(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x20,unaff_EBP + -0x2c);
    hObject = CreateFileA(*(LPCSTR *)(unaff_EBP + 8),0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,
                          (HANDLE)0x0);
    if (hObject == (HANDLE)0xffffffff) {
      GetLastError();
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
    }
    else {
      CloseHandle(hObject);
      FUN_005a509f(unaff_EBP + -0x14,unaff_EBP + -0x20);
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        iVar4 = unaff_EBP + -0x2c;
        FUN_005bab42(unaff_EBP + -0x20);
        puVar3 = (undefined4 *)FUN_005baa48(iVar4);
        *(undefined1 *)(puVar3 + 4) = 0;
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[3] = 0;
        *(undefined1 *)((int)puVar3 + 0x11) = 1;
        *(undefined1 *)((int)puVar3 + 0x12) = 0;
      }
      *(undefined1 *)(unaff_EBP + 0xb) = 1;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar2 = *(undefined1 *)(unaff_EBP + 0xb);
  }
  else {
    uVar2 = 0;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

