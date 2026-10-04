
uint FUN_00474b22(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  uVar2 = FUN_00634c24();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  iVar3 = extraout_ECX[10];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  if ((short)iVar3 == 0) {
    *(undefined2 *)(unaff_EBP + -0x2c) = 0xffff;
    *(undefined2 *)(unaff_EBP + -0x2a) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined2 *)(unaff_EBP + -0x28) = 0;
    *(undefined1 *)(unaff_EBP + -0x26) = 0;
    *(undefined1 *)(unaff_EBP + -0x25) = 0;
    FUN_0047542b(unaff_EBP + -0x2c,0);
    cVar1 = FUN_004749b7(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x14),
                         *(undefined4 *)(unaff_EBP + 0x10));
    if (cVar1 != '\0') {
      iVar3 = FUN_004750a6();
      *(undefined1 *)(unaff_EBP + 0xf) = 0;
      *(undefined2 *)(iVar3 + 4) = *(undefined2 *)(unaff_EBP + 0xc);
      *(undefined1 *)(unaff_EBP + 0x13) = DAT_006c4d5c;
      DAT_006c4d5c = 0;
      iVar3 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + 8) = iVar3;
      extraout_ECX[1] = 0;
      do {
        puVar4 = (ushort *)FUN_004750a6();
        if ((*puVar4 == 0xffff) || ((*puVar4 & 0x7fff) == 0xffff)) {
          FUN_00475463();
          (**(code **)(*extraout_ECX + 8))();
          if (extraout_ECX[7] == 0xfe) {
            *(undefined1 *)(unaff_EBP + 0xf) = 1;
            uVar2 = FUN_00474c34();
            return uVar2;
          }
          *(undefined1 *)(unaff_EBP + 0xf) = 0;
          uVar2 = FUN_00474c34();
          return uVar2;
        }
        iVar3 = FUN_00474cae(puVar4);
      } while ((iVar3 < 1) || (2 < iVar3));
      *(undefined4 *)(unaff_EBP + 0x14) = 0x44f;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + 0x14,&DAT_00698f30);
    }
    FUN_00475463();
    uVar2 = (**(code **)(*extraout_ECX + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2 & 0xffffff00;
}

