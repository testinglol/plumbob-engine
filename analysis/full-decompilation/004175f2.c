
undefined4 __thiscall FUN_004175f2(int *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    uVar7 = 0xffffffcf;
  }
  else {
    uVar7 = 0;
  }
  FUN_004659fc(uVar7);
  iVar3 = FUN_00401f6f();
  if (iVar3 == 0) {
    iVar3 = (**(code **)*param_3)();
    if (iVar3 != 0) {
      piVar1 = (int *)param_1[9];
      piVar4 = (int *)*piVar1;
      if (piVar4 != (int *)piVar1[1]) {
        do {
          iVar3 = FUN_0046f973(param_3);
          if (iVar3 == 0) goto LAB_0041765c;
          piVar4 = piVar4 + 0x14;
        } while (piVar4 != (int *)piVar1[1]);
      }
      piVar4 = (int *)0x0;
LAB_0041765c:
      if (piVar4 != (int *)0x0) {
        do {
          for (puVar5 = (undefined4 *)param_1[6]; puVar5 != (undefined4 *)0x0;
              puVar5 = (undefined4 *)*puVar5) {
            for (puVar6 = (undefined4 *)puVar5[2]; puVar6 != (undefined4 *)0x0;
                puVar6 = (undefined4 *)*puVar6) {
              if (puVar6[3] == *piVar4) {
                param_3 = (undefined4 *)puVar5[1];
                if (param_4 != 0) {
                  puVar5[3] = param_4;
                }
                goto LAB_00417697;
              }
            }
          }
          puVar6 = (undefined4 *)0x0;
LAB_00417697:
          if (param_2 == param_3) break;
          piVar4 = (int *)FUN_00416e82(piVar4);
          puVar6 = (undefined4 *)0x0;
        } while (piVar4 != (int *)0x0);
        if (puVar6 != (undefined4 *)0x0) {
          uVar7 = FUN_00417f1a(puVar6,param_4);
          FUN_004659fc(uVar7);
          return puVar6[4];
        }
      }
    }
    FUN_004659fc(0xffffff9d);
  }
  return 0;
}

