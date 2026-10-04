
undefined4 FUN_00513f10(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x10,0);
    iVar3 = FUN_005dd5e1(0x1f,0x7c,0x1f);
    extraout_ECX[0x19] = iVar3;
    cVar1 = FUN_005dbf32();
    if (cVar1 != '\0') {
      FUN_005a5631(0x135a,extraout_ECX + 0x67,4);
      FUN_005a5631(0x1359,extraout_ECX + 0x68,4);
      FUN_005a5631(0x135b,extraout_ECX + 0x69,4);
      FUN_005a5631(0x135c,extraout_ECX + 0x6a,4);
      FUN_005a5631(0x1334,extraout_ECX + 0x6b,4);
      FUN_005a5631(0x1335,extraout_ECX + 0x6c,4);
      piVar5 = (int *)extraout_ECX[0x67];
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x68))(DAT_006f2a64);
      }
      if ((int *)extraout_ECX[0x68] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x68] + 0x68))(DAT_006f2a64);
      }
      if ((int *)extraout_ECX[0x69] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x69] + 0x68))(DAT_006f2a64);
      }
      if ((int *)extraout_ECX[0x6a] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x6a] + 0x68))(DAT_006f2a64);
      }
      pvVar4 = operator_new(0x118);
      *(void **)(unaff_EBP + -0x10) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar4 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_0050f7c5(extraout_ECX[0x35]);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x65] = (int)piVar5;
      if (piVar5 != (int *)0x0) {
        cVar1 = (**(code **)(*piVar5 + 0xc))();
        if (cVar1 != '\0') {
          (**(code **)(*(int *)extraout_ECX[0x65] + 0x98))();
          (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x20))(extraout_ECX[0x65]);
          pvVar4 = operator_new(0x84);
          *(void **)(unaff_EBP + -0x10) = pvVar4;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar4 == (void *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_00510166(&DAT_006de560,&DAT_006de560,0,0,0,0,0,0,0);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          extraout_ECX[0x66] = iVar3;
          if (iVar3 != 0) {
            FUN_00503993(s_options_006cca9c);
          }
          cVar1 = FUN_00514110();
          if (cVar1 != '\0') {
            (**(code **)(*extraout_ECX + 0x88))();
            FUN_00517545(0);
            uVar2 = 1;
            goto LAB_00514102;
          }
        }
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005dbf32();
  }
LAB_00514102:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

