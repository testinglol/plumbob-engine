
void FUN_004e550a(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 0x10);
  cVar2 = FUN_004e5685(*(undefined4 *)(unaff_EBP + 0xc),piVar1);
  if (cVar2 != '\0') {
    FUN_004b4533(*(undefined4 *)(DAT_006e486c + 4));
    FUN_004b475c();
    iVar3 = *(int *)(DAT_006e54dc + 0x10);
    *(undefined1 *)(unaff_EBP + 0x12) = 1;
    *(char *)(unaff_EBP + 0x10) = (char)(iVar3 / 2);
    *(char *)(unaff_EBP + 0x11) = (char)(iVar3 / 2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00434d3d(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b463f(3,1,1);
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x14);
    FUN_004b4bbd(3);
    iVar3 = ((piVar1[3] - piVar1[1]) * 2) / 3;
    iVar4 = (piVar1[2] - *piVar1) / 2 + -0x40;
    *(int *)(unaff_EBP + -0x84) = iVar4;
    *(int *)(unaff_EBP + -0x80) = iVar3 + 0x13;
    FUN_004b97eb(unaff_EBP + -0x18,1,unaff_EBP + -0x94,0xffffffff);
    cVar2 = FUN_004a156c(*(undefined4 *)(unaff_EBP + 8),3,unaff_EBP + -0x1c,unaff_EBP + -0x20);
    if (cVar2 != '\0') {
      *(undefined1 *)(unaff_EBP + -0xd) = 0x7f;
      *(undefined1 *)(unaff_EBP + -0xe) = 0x7f;
      *(undefined1 *)(unaff_EBP + -0xf) = 0x7f;
      *(undefined1 *)(unaff_EBP + -0x10) = 0x7f;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *(char *)(unaff_EBP + 8) = (char)(*(int *)(unaff_EBP + -0x14) >> 4);
      *(char *)(unaff_EBP + 9) = (char)(*(int *)(unaff_EBP + -0x18) >> 4);
      *(undefined1 *)(unaff_EBP + 10) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_004c828c(unaff_EBP + -0xa4,unaff_EBP + 8,*(undefined4 *)(unaff_EBP + -0x20),0,iVar4,
                   iVar3 + -0x2d,0,unaff_EBP + -0x94,unaff_EBP + -0x10,1,0,0,0);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    FUN_004e586d(*(undefined4 *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

