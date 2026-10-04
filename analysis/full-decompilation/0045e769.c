
void FUN_0045e769(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  short sVar4;
  undefined4 uVar5;
  int extraout_ECX;
  undefined4 *puVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  sVar4 = FUN_00475126();
  iVar2 = *(int *)(extraout_ECX + 0xb00);
  *(int *)(unaff_EBP + -0x10) = (int)sVar4;
  if ((*(int *)(extraout_ECX + 0xb04) - iVar2) / 0xc == 0) goto LAB_0045e82b;
  puVar3 = *(undefined4 **)(extraout_ECX + 0xb04);
  piVar1 = puVar3 + -3;
  if (*(int *)(unaff_EBP + -0x10) == puVar3[-2] + -1) {
    *(short *)(*piVar1 + 0xc6) = *(short *)(*piVar1 + 0xc6) + -1;
    puVar6 = *(undefined4 **)(extraout_ECX + 0xb00);
    if (puVar6 != puVar3) {
      do {
        if (*(char *)(puVar6 + 2) != '\0') {
          *(undefined4 *)(extraout_ECX + 0xa54) = *puVar6;
        }
        puVar6 = puVar6 + 3;
      } while (puVar6 != *(undefined4 **)(extraout_ECX + 0xb04));
    }
LAB_0045e7f2:
    FUN_0045faa7(piVar1);
  }
  else if (*(int *)(unaff_EBP + -0x10) < (int)puVar3[-2]) {
    *(short *)(*piVar1 + 0xc6) = *(short *)(*piVar1 + 0xc6) + -1;
    goto LAB_0045e7f2;
  }
  if ((*(int *)(extraout_ECX + 0xb04) - *(int *)(extraout_ECX + 0xb00)) / 0xc == 0) {
    uVar5 = FUN_0041ed45();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0045e839(uVar5);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
LAB_0045e82b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

