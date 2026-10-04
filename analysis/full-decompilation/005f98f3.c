
undefined1 FUN_005f98f3(void)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar8;
  
  FUN_00634c24();
  if ((*(int **)(extraout_ECX + 0xbc) != (int *)0x0) &&
     (piVar1 = (int *)**(int **)(extraout_ECX + 0xbc), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))();
    FUN_006321f0(**(undefined4 **)(extraout_ECX + 0xbc));
    **(undefined4 **)(extraout_ECX + 0xbc) = 0;
  }
  if (*(int *)(extraout_ECX + 0xbc) == 0) {
    pvVar5 = operator_new(0x38);
    *(void **)(unaff_EBP + -0x14) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_005f9bfd();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0xbc) = uVar6;
  }
  if (*(int *)(extraout_ECX + 0xbc) == 0) {
    uVar4 = 0;
    goto LAB_005f9bef;
  }
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 4) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 8) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0xc) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x10) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x14) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x18) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x1c) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x20) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x24) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x34) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x2c) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x28) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 0x30) = 0;
  FUN_005d4c15(unaff_EBP + -0x20,4);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d4d82();
  cVar3 = FUN_00460748(unaff_EBP + -0x20,&DAT_006d8128);
  if (cVar3 == '\0') {
    uVar6 = FUN_005d4c15(unaff_EBP + -0x2c,2);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    uVar4 = FUN_00460748(uVar6,&DAT_006d8130);
    *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      pvVar5 = operator_new(0xf6c);
      *(void **)(unaff_EBP + -0x14) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      if (pvVar5 == (void *)0x0) goto LAB_005f9ae5;
      uVar6 = FUN_005fbcf8();
      goto LAB_005f9ae7;
    }
    uVar6 = FUN_005d4be4(unaff_EBP + -0x2c,3);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    uVar4 = FUN_00460748(uVar6,&PTR_LAB_006d8124);
    *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      pvVar5 = operator_new(0x108c);
      *(void **)(unaff_EBP + -0x14) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      if (pvVar5 == (void *)0x0) goto LAB_005f9ae5;
      uVar6 = FUN_005f8b7f();
      goto LAB_005f9ae7;
    }
LAB_005f9bde:
    uVar4 = 0;
  }
  else {
    pvVar5 = operator_new(0x48);
    *(void **)(unaff_EBP + -0x14) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar5 == (void *)0x0) {
LAB_005f9ae5:
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_005fba41();
    }
LAB_005f9ae7:
    puVar7 = *(undefined4 **)(extraout_ECX + 0xbc);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *puVar7 = uVar6;
    cVar3 = (**(code **)(*(int *)**(undefined4 **)(extraout_ECX + 0xbc) + 4))
                      (*(undefined4 *)(extraout_ECX + 8));
    if (cVar3 == '\0') goto LAB_005f9bde;
    puVar7 = (undefined4 *)(**(code **)(*(int *)**(undefined4 **)(extraout_ECX + 0xbc) + 0x1c))();
    *(undefined4 *)(extraout_ECX + 0xa8) = *puVar7;
    *(undefined4 *)(extraout_ECX + 0xac) = puVar7[1];
    *(undefined4 *)(extraout_ECX + 0xb0) = puVar7[2];
    *(undefined4 *)(extraout_ECX + 0xb4) = puVar7[3];
    *(undefined2 *)(extraout_ECX + 0xb8) = *(undefined2 *)(puVar7 + 4);
    *(uint *)(*(int *)(extraout_ECX + 0xbc) + 4) =
         (*(uint *)(extraout_ECX + 0xb0) >> 3 & 0xffffff) * 2 * *(int *)(extraout_ECX + 0xc4) * 6;
    *(uint *)(*(int *)(extraout_ECX + 0xbc) + 8) =
         *(uint *)(*(int *)(extraout_ECX + 0xbc) + 4) / (uint)(*(int *)(extraout_ECX + 0xc4) * 6);
    uVar6 = FUN_005d4c15(unaff_EBP + -0x2c,2);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    uVar4 = FUN_00460748(uVar6,&DAT_006d8130);
    *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      uVar2 = *(uint *)(*(int *)(extraout_ECX + 0xbc) + 8);
      uVar8 = uVar2 & 3;
      if (uVar8 != 0) {
        *(uint *)(*(int *)(extraout_ECX + 0xbc) + 8) = uVar2 + (4 - uVar8);
      }
    }
    *(int *)(*(int *)(extraout_ECX + 0xbc) + 4) =
         *(int *)(*(int *)(extraout_ECX + 0xbc) + 8) * *(int *)(extraout_ECX + 0xc4) * 6;
    *(undefined4 *)(extraout_ECX + 0xa4) = *(undefined4 *)(*(int *)(extraout_ECX + 0xbc) + 4);
    uVar4 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_005f9bef:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

