
void FUN_0050cca5(void)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  int *piVar9;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_d4 [8];
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  
  FUN_00634c24();
  iVar8 = *(int *)(extraout_ECX + 0x84);
  iVar6 = *(int *)(extraout_ECX + 0x7c);
  *(int *)(unaff_EBP + -0x10) = *(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80);
  FUN_004573f9();
  uStack_c8 = 0x50ccf2;
  FUN_004ce4a9();
  uStack_c8 = 0x50ccf9;
  uVar3 = FUN_004cdca5();
  *(undefined4 *)(unaff_EBP + -0x28) = uVar3;
  if (*(int *)(extraout_ECX + 0x108) == 0) {
    uStack_c8 = 0x50cd0d;
    pvVar4 = operator_new(100);
    *(void **)(unaff_EBP + -0x14) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_005dfb13();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x108) = uVar3;
  }
  cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x18))();
  if (cVar1 != '\0') {
    uStack_c8 = 0;
    uStack_cc = 0;
    uVar3 = **(undefined4 **)(extraout_ECX + 0x108);
    *(undefined1 **)(unaff_EBP + -0x14) = auStack_d4;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    FUN_00436a50(4);
    cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0xc))
                      (iVar8 - iVar6,*(undefined4 *)(unaff_EBP + -0x10));
    if ((cVar1 != '\0') && (cVar1 = FUN_005df69e(), cVar1 != '\0')) {
      cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x20))(0x10);
      if (cVar1 != '\0') {
        iVar8 = *(int *)(extraout_ECX + 0x104);
        *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar8 + 0x14);
        *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar8 + 0x18);
        *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar8 + 0x1c);
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar8 + 0x20);
        (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x9c))
                  (iVar8,unaff_EBP + -0x38,unaff_EBP + -0x38,0);
        (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x24))(0x10);
      }
      cVar1 = (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x108) + 0x5c) + 0x20))(1);
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x108) + 0x5c) + 0x40))
                  (0xffff,&DAT_006f3648,0);
        (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x108) + 0x5c) + 0x24))(0x10);
      }
      uVar3 = FUN_004573f9(*(undefined4 *)(extraout_ECX + 0x108),&DAT_006f3648,0);
      FUN_004e5425(uVar3);
      if ((*(char *)(extraout_ECX + 0x110) == '\0') || (*(char *)(extraout_ECX + 0x111) == '\0')) {
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
      }
      else {
        sVar2 = FUN_00432249();
        *(int *)(unaff_EBP + -0x10) = (int)sVar2;
        uVar3 = __ftol();
        *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
      }
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xc0) = &PTR_FUN_0066643c;
      uVar3 = 1;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar5 = FUN_0041532c(9,unaff_EBP + -0xc0,0);
      FUN_004fff98(0x88,uVar5);
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar6 = FUN_0047168f();
      piVar9 = *(int **)(extraout_ECX + 0x10c);
      iVar8 = piVar9[0x47];
      *(undefined4 *)(unaff_EBP + -0x14) = 3;
      *(undefined4 *)(unaff_EBP + -0x10) = 2;
      if (*(short *)(*(int *)(iVar8 + 0x60) + 0x8a) != 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 6;
        uVar3 = 4;
        *(undefined4 *)(unaff_EBP + -0x10) = 5;
      }
      if (iVar6 == 6) {
        if ((piVar9 == (int *)0x0) || (cVar1 = (**(code **)(*piVar9 + 0x70))(), cVar1 != '\0')) {
          if (*(int *)(unaff_EBP + -0x24) != 0) {
            uVar3 = *(undefined4 *)(unaff_EBP + -0x10);
          }
        }
        else {
          uVar3 = *(undefined4 *)(unaff_EBP + -0x14);
        }
        uVar3 = FUN_004705f2(uVar3,0xffffffff);
        FUN_005d4bbf(uVar3);
        sVar7 = _strlen(&DAT_006cc764);
        iVar8 = FUN_004558e0(&DAT_006cc764,0,sVar7);
        if (iVar8 != -1) {
          if (*(int *)(unaff_EBP + -0x28) == 0) {
            FUN_00455800(iVar8,1,s_<Unknown>_006cc758);
          }
          else {
            uVar3 = FUN_005ed3c4();
            FUN_00455790(iVar8,1,uVar3);
          }
        }
        sVar7 = _strlen(&DAT_006c10a0);
        iVar8 = FUN_004558e0(&DAT_006c10a0,0,sVar7);
        *(int *)(unaff_EBP + -0x28) = iVar8;
        if (iVar8 != -1) {
          FUN_005d48d9();
          piVar9 = DAT_006fe8bc;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          piVar9 = (int *)(**(code **)(*piVar9 + 4))();
          (**(code **)(*piVar9 + 0x7c))
                    (*(int *)(unaff_EBP + -0x24),*(int *)(unaff_EBP + -0x24) >> 0x1f,
                     unaff_EBP + -0x44);
          FUN_00455790(*(undefined4 *)(unaff_EBP + -0x28),1,unaff_EBP + -0x44);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005b8770();
        }
        piVar9 = *(int **)(extraout_ECX + 0xd8);
        *(undefined4 *)(unaff_EBP + -0x54) = DAT_006f3620;
        *(undefined4 *)(unaff_EBP + -0x50) = DAT_006f3624;
        *(undefined4 *)(unaff_EBP + -0x4c) = DAT_006f3628;
        *(undefined4 *)(unaff_EBP + -0x48) = DAT_006f362c;
        (**(code **)(*piVar9 + 0x80))
                  (*(undefined4 *)(extraout_ECX + 0x108),unaff_EBP + -0x54,
                   *(undefined4 *)(unaff_EBP + -0x20),
                   *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x20),0);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

