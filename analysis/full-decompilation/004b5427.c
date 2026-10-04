
void FUN_004b5427(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  undefined4 extraout_ECX;
  int iVar7;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  pvVar4 = operator_new(0xc);
  *(void **)(unaff_EBP + -0x18) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    FUN_0055e4e2(unaff_EBP + -0xd);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0047c545(0x1000);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(void **)(unaff_EBP + -0x18) = pvVar4;
  if (pvVar4 != (void *)0x0) {
    FUN_004b5576(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    pcVar3 = *(char **)(unaff_EBP + 8);
    do {
      iVar8 = 0;
      do {
        iVar7 = (int)pcVar3[1] + *(int *)(unaff_EBP + -0x14);
        iVar5 = *pcVar3 + iVar8;
        if ((((-1 < iVar5) && (iVar5 < 0x40)) && (-1 < iVar7)) && (iVar7 < 0x40)) {
          puVar1 = (undefined1 *)
                   (**(int **)(unaff_EBP + -0x18) +
                   (*(char *)(unaff_EBP + -0x14) * 0x40 + (int)(char)iVar8) * 4);
          puVar2 = (undefined1 *)
                   (**(int **)(unaff_EBP + -0x1c) + ((char)iVar7 * 0x40 + (int)(char)iVar5) * 4);
          if (puVar2 != puVar1) {
            *puVar2 = *puVar1;
            puVar2[1] = puVar1[1];
            puVar2[2] = puVar1[2];
            puVar2[3] = puVar1[3];
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x40);
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    } while (*(int *)(unaff_EBP + -0x14) < 0x40);
    iVar8 = 0;
    do {
      iVar5 = 0;
      do {
        if (((iVar5 - *pcVar3 < 0) && (0x3f < iVar5 - *pcVar3)) &&
           ((iVar8 - pcVar3[1] < 0 && (0x3f < iVar8 - pcVar3[1])))) {
          iVar6 = (char)iVar8 * 0x40 + (int)(char)iVar5;
          iVar7 = **(int **)(unaff_EBP + -0x1c);
          *(undefined1 *)(iVar7 + 3 + iVar6 * 4) = 0x7f;
          *(undefined1 *)(iVar7 + 2 + iVar6 * 4) = 0x7f;
          *(undefined1 *)(iVar7 + 1 + iVar6 * 4) = 0x7f;
          *(undefined1 *)(iVar7 + iVar6 * 4) = 0x7f;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x40);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x40);
    FUN_0047c52f();
    FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x18));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

