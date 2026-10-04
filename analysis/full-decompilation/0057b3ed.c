
undefined4 FUN_0057b3ed(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  FUN_00636080();
  uVar2 = *(undefined4 *)(extraout_ECX + 0x24);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  iVar1 = FUN_00635845(uVar2,&DAT_006cf464);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar4 = 0;
    while( true ) {
      iVar1 = FUN_00636bfa(iVar1,&DAT_006c0a70,unaff_EBP + -0x1038);
      if (iVar1 == -1) break;
      if (*(char *)(unaff_EBP + -0x1038) == '[') {
        puVar3 = (undefined1 *)FUN_00636450(unaff_EBP + -0x1038,0x5d);
        *puVar3 = 0;
        FUN_005d4956(unaff_EBP + -0x1037);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar4 = FUN_0057b520(unaff_EBP + -0x38);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_0057b4f2:
        FUN_005b8770();
      }
      else if (iVar4 != 0) {
        iVar1 = FUN_00636450(unaff_EBP + -0x1038,0x3d);
        if (iVar1 != 0) {
          FUN_005d4956(unaff_EBP + -0x1038);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          FUN_005d4a0d(unaff_EBP + -0x2c,&DAT_006c42ec);
          uVar2 = *(undefined4 *)(iVar4 + 0x10);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          (**(code **)(iVar4 + 0xc))(unaff_EBP + -0x2c,unaff_EBP + -0x20,uVar2);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          goto LAB_0057b4f2;
        }
      }
      iVar1 = *(int *)(unaff_EBP + -0x10);
    }
    FUN_0063558d(*(undefined4 *)(unaff_EBP + -0x10));
    uVar2 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

