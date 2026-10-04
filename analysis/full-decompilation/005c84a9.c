
undefined4 FUN_005c84a9(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  puVar1 = *(undefined4 **)(*(int *)(unaff_EBP + 0xc) + 4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_005c8536(0);
  }
  else {
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_006772d8,unaff_EBP + 0xc);
    if (-1 < iVar2) {
      FUN_005c8536(*(undefined4 *)(unaff_EBP + 0xc));
      iVar2 = **(int **)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      (**(code **)(iVar2 + 8))(*(int **)(unaff_EBP + 0xc));
      FUN_005c858c(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      FUN_005c7c9d();
      uVar3 = *(undefined4 *)(unaff_EBP + 8);
      goto LAB_005c852a;
    }
    FUN_005c8536(0);
  }
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
LAB_005c852a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

