
void __thiscall
FUN_0053d257(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            char param_6)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x54) = param_4;
  *(undefined4 *)(param_1 + 0x58) = param_2;
  *(undefined1 *)(param_1 + 0x50) = 1;
  *(undefined4 *)(param_1 + 0x5c) = param_3;
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_0053c286();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_0053c286();
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (param_6 != '\0') {
    switch(*(undefined4 *)(param_5 + 0x10)) {
    case 0:
code_r0x0053d2ed:
      *(int *)(param_1 + 0x10) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 1;
      break;
    case 1:
code_r0x0053d2bd:
      *(int *)(param_1 + 0x18) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 4;
      break;
    case 2:
code_r0x0053d2ff:
      *(int *)(param_1 + 0x14) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 2;
      break;
    case 3:
code_r0x0053d2cf:
      *(int *)(param_1 + 0x1c) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 8;
      break;
    case 4:
code_r0x0053d2f6:
      *(int *)(param_1 + 0x10) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 0x10;
      break;
    case 5:
code_r0x0053d2c6:
      *(int *)(param_1 + 0x18) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 0x40;
      break;
    case 6:
code_r0x0053d2d8:
      *(int *)(param_1 + 0x1c) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 0x80;
      break;
    case 7:
code_r0x0053d308:
      *(int *)(param_1 + 0x14) = param_5;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 0x20;
    default:
      break;
    }
LAB_0053d30f:
    if (*(int *)(param_1 + 0x18) != 0) {
      piVar1 = (int *)(*(int *)(param_1 + 0x18) + 0x58);
      *piVar1 = *piVar1 + 1;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 0x58);
      *piVar1 = *piVar1 + 1;
    }
    if (param_1 == *(int *)(param_5 + 0x20)) {
      iVar4 = *(int *)(param_5 + 0x30);
    }
    else {
      iVar4 = *(int *)(param_5 + 0x34) + -6;
    }
    cVar2 = *(char *)(iVar4 + 1);
    if ((((cVar2 == '\x02') || (cVar2 == '\f')) || (cVar2 == '\r')) || (cVar2 == '\x0e')) {
      *(undefined1 *)(param_1 + 0xb) = *(undefined1 *)(param_1 + 8);
    }
    else {
      *(undefined1 *)(param_1 + 10) = *(undefined1 *)(param_1 + 8);
    }
    FUN_00438c54(param_1 + 10);
    uVar3 = FUN_0053cf03();
    *(undefined1 *)(param_1 + 0x24) = uVar3;
    FUN_00438c54(param_1 + 9);
    uVar3 = FUN_0053cf03();
    *(undefined1 *)(param_1 + 0x25) = uVar3;
    return;
  }
  switch(*(undefined4 *)(param_5 + 0x10)) {
  case 0:
    goto code_r0x0053d2bd;
  case 1:
    goto code_r0x0053d2ed;
  case 2:
    goto code_r0x0053d2cf;
  case 3:
    goto code_r0x0053d2ff;
  case 4:
    goto code_r0x0053d2c6;
  case 5:
    goto code_r0x0053d2f6;
  case 6:
    goto code_r0x0053d308;
  case 7:
    goto code_r0x0053d2d8;
  default:
    goto LAB_0053d30f;
  }
}

