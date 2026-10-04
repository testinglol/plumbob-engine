
void FUN_004d1aa0(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *extraout_ECX;
  char cVar7;
  int unaff_EBP;
  float10 fVar8;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d51f5(s_SIM__Simulate_006c7c44,0);
  FUN_004b406a();
  cVar2 = FUN_004d3d05();
  piVar1 = DAT_006e54ac;
  piVar5 = extraout_ECX;
  if ((cVar2 == '\0') || (DAT_006e54ac == (int *)0x0)) goto LAB_004d1c2a;
  cVar2 = (**(code **)(*DAT_006e54ac + 0x68))();
  if (cVar2 != '\0') goto LAB_004d1c2a;
  uVar4 = FUN_00492d2c();
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x20) = DAT_006e57e4;
  iVar6 = DAT_006e57e0;
  piVar5 = *(int **)(DAT_006e486c + 4);
  uVar3 = (**(code **)(*piVar5 + 0x38))();
  cVar2 = (char)(*(int *)(unaff_EBP + -0x20) >> 4);
  *(char *)(unaff_EBP + -0x18) = cVar2;
  cVar7 = (char)(iVar6 >> 4);
  *(char *)(unaff_EBP + -0x17) = cVar7;
  *(undefined1 *)(unaff_EBP + -0x16) = uVar3;
  *(int *)(unaff_EBP + -0x30) = (int)cVar2;
  iVar6 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar6 + 4);
  uVar4 = (**(code **)(*piVar5 + 0x38))();
  FUN_004a9e60(unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + -0x30),(int)cVar7,uVar4,DAT_006f0088,0)
  ;
  iVar6 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  cVar2 = (**(code **)(iVar6 + 100))();
  if (cVar2 == '\0') {
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      FUN_005d48d9();
      piVar5 = DAT_006fe8bc;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      piVar5 = (int *)(**(code **)(*piVar5 + 4))();
      (**(code **)(*piVar5 + 0x7c))
                (*(int *)(unaff_EBP + -0x1c),*(int *)(unaff_EBP + -0x1c) >> 0x1f,unaff_EBP + -0x28);
      FUN_004d28b2((int)*(short *)(unaff_EBP + -0x12),(int)*(short *)(unaff_EBP + -0x14),
                   unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_004d1c17;
    }
    FUN_004d2900();
  }
  else {
    wsprintfA((LPSTR)(unaff_EBP + -0x140),*(LPCSTR *)(*(int *)(unaff_EBP + -0x10) + 0x11c4));
    uVar4 = FUN_005d4956();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004d28b2((int)*(short *)(unaff_EBP + -0x12),(int)*(short *)(unaff_EBP + -0x14),uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_004d1c17:
    FUN_005b8770();
  }
  piVar5 = *(int **)(unaff_EBP + -0x10);
LAB_004d1c2a:
  FUN_00476675();
  if (((char)piVar5[0x46] == '\0') && (*(char *)((int)piVar5 + 0x119) == '\0')) {
    *(undefined1 *)(piVar5 + 0x46) = 1;
    FUN_0046daf2();
    *(undefined1 *)(piVar5 + 0x46) = 0;
  }
  (**(code **)(*piVar5 + 0x168))();
  FUN_004733e4();
  iVar6 = FUN_00473417();
  if (iVar6 != 0) {
    fVar8 = (float10)FUN_0047318e();
    FUN_00635858(&DAT_006f0ed8,s_FPS___3_1lf_006c7c38,(double)fVar8);
    FUN_004d387d();
  }
  FUN_005d51f5(s_SIM__End_006c7c2c,0);
  FUN_004b406a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

