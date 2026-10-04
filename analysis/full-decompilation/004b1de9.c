
void FUN_004b1de9(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  int iVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar5 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  iVar4 = *(int *)(*piVar5 + 0x14);
  piVar5 = (int *)(iVar4 + 0x84);
  *(int **)(unaff_EBP + -0x18) = piVar5;
  piVar5 = (int *)*piVar5;
  if (piVar5 != *(int **)(iVar4 + 0x88)) {
    do {
      piVar6 = (int *)*piVar5;
      cVar1 = (char)piVar6[0x3f];
      uVar2 = *(undefined1 *)((int)piVar6 + 0xfd);
      *(char *)(unaff_EBP + -0x10) = cVar1;
      *(undefined1 *)(unaff_EBP + -0xf) = uVar2;
      cVar3 = *(char *)((int)piVar6 + 0xfe);
      *(char *)(unaff_EBP + -0xe) = cVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar4 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x18);
      if (((((cVar3 <= iVar4) && ('\0' < cVar1)) &&
           (iVar7 = *(int *)(DAT_006e54dc + 0x10) + -1, cVar1 < iVar7)) &&
          (('\0' < *(char *)(unaff_EBP + -0xf) && (*(char *)(unaff_EBP + -0xf) < iVar7)))) ||
         (((int)cVar3 == iVar4 + 1 && ((short)piVar6[0x177] != 0)))) {
        piVar6 = (int *)(**(code **)(*piVar6 + 0x8c))();
        (**(code **)(*piVar6 + 0x54))(0);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      piVar5 = piVar5 + 1;
    } while (piVar5 != *(int **)(*(int *)(unaff_EBP + -0x18) + 4));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

