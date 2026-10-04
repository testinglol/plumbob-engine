
uint FUN_0054f9e4(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *_Str;
  size_t sVar5;
  void *pvVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    uVar2 = FUN_005dbf32();
    if ((char)uVar2 != '\0') {
      FUN_004cb1a2(200,100);
      uVar2 = FUN_005a5631(0x13f3,extraout_ECX + 0x37,4);
      if (extraout_ECX[0x37] != 0) {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x80) = &PTR_FUN_0066643c;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        uVar3 = FUN_0041532c(9,unaff_EBP + -0x80,0);
        cVar1 = FUN_004fff98(0x86,uVar3);
        if (cVar1 != '\0') {
          iVar4 = FUN_0047168f();
          if (0x26 < iVar4) {
            FUN_00471655(unaff_EBP + -0x14);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            iVar4 = 0;
            do {
              _Str = (char *)FUN_0046fc7a();
              sVar5 = _strlen(_Str);
              pvVar6 = operator_new(sVar5 + 1);
              *(void **)(extraout_ECX[0x3b] + iVar4) = pvVar6;
              if (*(int *)(extraout_ECX[0x3b] + iVar4) == 0) goto LAB_0054fb09;
              uVar3 = FUN_0046fc7a();
              FUN_006358b0(*(undefined4 *)(extraout_ECX[0x3b] + iVar4),uVar3);
              iVar4 = iVar4 + 4;
              FUN_005c11ce();
            } while (iVar4 < 0x9c);
            (**(code **)(*extraout_ECX + 0x90))(0x40000,1);
LAB_0054fb09:
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_0042004f();
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar2 = FUN_00470467();
      }
    }
    uVar2 = uVar2 & 0xffffff00;
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

