
undefined4 FUN_00410a3c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x144) == 0) {
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
    }
    *(undefined4 **)(extraout_ECX + 0x144) = puVar2;
    if ((puVar2 != (undefined4 *)0x0) && (iVar1 = *(int *)(extraout_ECX + 0x140), iVar1 != 0)) {
      *(undefined4 **)(unaff_EBP + -0x18) = puVar2;
      *(undefined4 *)(unaff_EBP + -0x14) = 0x46414d68;
      *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_0066664c;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00464faf(unaff_EBP + -0x1c,iVar1,0);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00465055();
      FUN_00420028(iVar1);
      *(undefined4 *)(extraout_ECX + 0x140) = 0;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(extraout_ECX + 0x144);
}

