
void FUN_00549a98(void)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  int *piVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (extraout_ECX[0x47] - extraout_ECX[0x46] >> 2 != 0) {
    *(int **)(unaff_EBP + -0x14) = extraout_ECX + 0x49;
    do {
      piVar7 = (int *)**(int **)(unaff_EBP + -0x14);
      if (piVar7 != (int *)0x0) {
        iVar6 = *(int *)(unaff_EBP + -0x10);
        piVar7[0x66] = *(int *)(extraout_ECX[0x46] + iVar6 * 4);
        FUN_005c1719();
        iVar1 = extraout_ECX[0x46];
        *(undefined4 *)(unaff_EBP + -4) = 0;
        cVar4 = FUN_004e93e4(*(undefined4 *)(iVar1 + iVar6 * 4),unaff_EBP + -0x18);
        if (cVar4 != '\0') {
          iVar6 = *piVar7;
          uVar5 = FUN_004096c2(4,3);
          (**(code **)(iVar6 + 0x19c))(uVar5);
        }
        FUN_004ec1a7(0x69);
        FUN_004ec186(0x55);
        piVar7[0x51] = DAT_006f5010;
        piVar7[0x52] = DAT_006f5014;
        FUN_0046f824(unaff_EBP + -0x124,0,0x100);
        iVar6 = extraout_ECX[0x46];
        *(undefined ***)(unaff_EBP + -0x130) = &PTR_FUN_00666524;
        FUN_004e9d38(*(undefined4 *)(iVar6 + *(int *)(unaff_EBP + -0x10) * 4),unaff_EBP + -0x130);
        FUN_005d4956(*(undefined4 *)(unaff_EBP + -300));
        iVar6 = *piVar7;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        (**(code **)(iVar6 + 0x9c))(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        piVar2 = DAT_006f2a9c;
        FUN_005e4071(DAT_006f2a9c);
        iVar6 = (**(code **)(*piVar2 + 0x58))();
        piVar7[0x58] = 1;
        piVar7[0x47] = 0;
        piVar7[0x48] = 0x69 - (iVar6 * 2 + 2);
        piVar7[0x49] = 0x55;
        piVar7[0x4a] = 0x69;
        piVar7[0x59] = 1;
        piVar7[0x3e] = 1;
        FUN_005e46f0(0);
        (**(code **)(*piVar7 + 0x94))();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005a5e09();
      }
      iVar6 = extraout_ECX[0x47];
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar1 = extraout_ECX[0x46];
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar6 - iVar1 >> 2));
  }
  iVar6 = extraout_ECX[0x47] - extraout_ECX[0x46] >> 2;
  if (iVar6 < 8) {
    piVar7 = extraout_ECX + iVar6 + 0x49;
    iVar6 = 8 - iVar6;
    do {
      if ((int *)*piVar7 != (int *)0x0) {
        (**(code **)(*(int *)*piVar7 + 0x98))();
      }
      piVar7 = piVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if ((((uint)(extraout_ECX[0x47] - extraout_ECX[0x46] >> 2) < 8) &&
      (iVar6 = extraout_ECX[0x45], iVar6 != 0)) &&
     (iVar6 = *(int *)(iVar6 + 0xe8) - *(int *)(iVar6 + 0xe4), iVar6 != 1 && -1 < iVar6 + -1)) {
    cVar4 = '\x01';
  }
  else {
    cVar4 = '\0';
  }
  piVar7 = (int *)extraout_ECX[0x52];
  if ((char)piVar7[0x5a] != cVar4) {
    *(char *)(piVar7 + 0x5a) = cVar4;
    (**(code **)(*piVar7 + 0x168))();
  }
  piVar2 = (int *)extraout_ECX[0x55];
  bVar3 = extraout_ECX[0x47] - extraout_ECX[0x46] >> 2 != 0;
  piVar7 = piVar2 + 0x5a;
  if ((bool)(char)*piVar7 != bVar3) {
    *(bool *)piVar7 = bVar3;
    (**(code **)(*piVar2 + 0x168))();
  }
  piVar2 = (int *)extraout_ECX[0x53];
  piVar7 = piVar2 + 0x5a;
  if ((bool)(char)*piVar7 != (extraout_ECX[0x51] != -1)) {
    *(bool *)piVar7 = extraout_ECX[0x51] != -1;
    (**(code **)(*piVar2 + 0x168))();
  }
  piVar2 = (int *)extraout_ECX[0x54];
  piVar7 = piVar2 + 0x5a;
  if ((bool)(char)*piVar7 != (extraout_ECX[0x51] != -1)) {
    *(bool *)piVar7 = extraout_ECX[0x51] != -1;
    (**(code **)(*piVar2 + 0x168))();
  }
  if (extraout_ECX[0x51] != -1) {
    FUN_005e46f0(1);
  }
  (**(code **)(*extraout_ECX + 0x168))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

