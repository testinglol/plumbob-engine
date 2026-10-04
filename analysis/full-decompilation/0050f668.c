
void __thiscall FUN_0050f668(int param_1,int param_2)

{
  int iVar1;
  
  switch(*(undefined4 *)(param_1 + 0x194)) {
  case 0:
  case 8:
    iVar1 = (int)*(short *)(param_2 + 0x5e8);
    break;
  case 1:
  case 9:
    iVar1 = (int)*(short *)(param_2 + 0x5ea);
    break;
  case 2:
  case 10:
    iVar1 = (int)*(short *)(param_2 + 0x5ec);
    break;
  case 3:
  case 0xb:
    iVar1 = (int)*(short *)(param_2 + 0x5ee);
    break;
  case 4:
    iVar1 = (int)*(short *)(param_2 + 0x5f0);
    break;
  case 5:
    iVar1 = (int)*(short *)(param_2 + 0x5f2);
    break;
  case 6:
    iVar1 = (int)*(short *)(param_2 + 0x5f4);
    break;
  case 7:
    iVar1 = (int)*(short *)(param_2 + 0x5f6);
    break;
  case 0xc:
    iVar1 = (int)*(short *)(param_2 + 0x5a6);
    break;
  case 0xd:
    iVar1 = (int)*(short *)(param_2 + 0x5a8);
    break;
  case 0xe:
    iVar1 = (int)*(short *)(param_2 + 0x5ac);
    break;
  case 0xf:
    iVar1 = (int)*(short *)(param_2 + 0x5b4);
    break;
  case 0x10:
    iVar1 = (int)*(short *)(param_2 + 0x5c0);
    break;
  case 0x11:
    iVar1 = (int)*(short *)(param_2 + 0x5f8);
    break;
  case 0x12:
    iVar1 = (int)*(short *)(param_2 + 0x5fa);
    break;
  default:
    goto LAB_0050f74c;
  }
  *(int *)(param_1 + 0x198) = iVar1 / 100;
LAB_0050f74c:
  if (10 < *(int *)(param_1 + 0x198)) {
    *(int *)(param_1 + 0x198) = 10;
  }
  if ((param_1 == *(int *)(*(int *)(param_1 + 0x19c) + 0x14)) && (*(int *)(param_1 + 0xe0) != 0)) {
    FUN_0050f513();
  }
  return;
}

