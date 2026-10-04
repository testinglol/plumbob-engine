
void FUN_0052d282(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x28) = extraout_ECX;
  piVar5 = *(int **)extraout_ECX[0x3f];
  *(int **)(unaff_EBP + -0x24) = piVar5 + 0x13;
  FUN_005b86bd(piVar5 + 0x13);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4956(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (piVar5 != (int *)0x0) {
    iVar3 = FUN_004e99a9();
    *(int *)(unaff_EBP + -0x14) = iVar3;
    if (iVar3 != -1) {
      iVar3 = FUN_0040542d();
      if (iVar3 != 0) {
        uVar4 = FUN_00405271(unaff_EBP + -0x40,*(undefined4 *)(unaff_EBP + -0x14));
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b8770();
        uVar1 = FUN_00405333(*(undefined4 *)(unaff_EBP + -0x14));
        *(undefined1 *)(unaff_EBP + -0xd) = uVar1;
      }
      (**(code **)(*piVar5 + 0x94))();
      if (*(char *)(unaff_EBP + -0xd) == '\0') {
        wsprintfA((LPSTR)(unaff_EBP + -0x140),(LPCSTR)extraout_ECX[0x74],
                  *(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + 8));
        piVar6 = extraout_ECX;
      }
      else {
        wsprintfA((LPSTR)(unaff_EBP + -0x140),&DAT_006c08e0,*(undefined4 *)(unaff_EBP + -0x20),
                  *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
        piVar6 = *(int **)(unaff_EBP + -0x28);
      }
      FUN_005d4956(unaff_EBP + -0x140);
      iVar3 = *piVar5;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      (**(code **)(iVar3 + 0x9c))(unaff_EBP + -0x40);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      (**(code **)(*piVar5 + 0x168))();
      cVar2 = FUN_005d49dc(*(undefined4 *)(unaff_EBP + -0x24));
      if (cVar2 == '\0') {
        piVar5 = (int *)(**(code **)(*piVar6 + 0x18))();
        (**(code **)(*piVar5 + 0x168))();
      }
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

